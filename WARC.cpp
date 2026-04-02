 #include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

#include "Motor.h"
#include "WARC.h"

const char* ap_ssid = "ESP32_RC";
const char* ap_pass = "12345678";

WebServer server(80);

#define BUZZER_PIN 14

// ================= PAGE =================
const char page[] PROGMEM = R"====(

<!DOCTYPE html>
<html>

<head>
<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">

<style>

body{
 font-family:Arial;
 display:flex;
 flex-direction:column;
 align-items:center;
 background:#111;
 color:#ddd;

 user-select:none;
 -webkit-user-select:none;
 -ms-user-select:none;
}

h1,h2{ color:#4fd1c5; }

.arrows{ font-size:70px;color:#eee; }
.circularArrows{ font-size:80px;color:#bbb; }

td{
 background:#1c1c1c;
 border-radius:35%;
 box-shadow:4px 4px #000;
 text-align:center;
}

td:active{
 transform:translate(4px,4px);
 box-shadow:none;
}

#buzzer{ background:#3a1f1f; }

table{
 width:400px;
 margin:auto;
 table-layout:fixed;
}

</style>

<script>

/* ===== SEND COMMAND ===== */
function send(c)
{
 fetch('/'+c);
}

/* ===== TOUCH + MOUSE BIND ===== */
function bind(id,cmd)
{
 let el=document.getElementById(id);

 el.onmousedown  = ()=>send(cmd);
 el.ontouchstart = ()=>send(cmd);

 el.onmouseup    = ()=>send('s');
 el.onmouseleave = ()=>send('s');
 el.ontouchend   = ()=>send('s');
}

/* ===== KEYBOARD CONTROL ===== */

const keys = {};

document.addEventListener("keydown",function(e)
{
 keys[e.key.toLowerCase()] = true;
 handleKeys();
});

document.addEventListener("keyup",function(e)
{
 keys[e.key.toLowerCase()] = false;
 handleKeys();
});

function handleKeys()
{
 /* DIAGONAL */
 if((keys["w"]||keys["arrowup"]) && keys["a"])
  return send("slf");

 if((keys["w"]||keys["arrowup"]) && keys["d"])
  return send("srf");

 if((keys["s"]||keys["arrowdown"]) && keys["a"])
  return send("slb");

 if((keys["s"]||keys["arrowdown"]) && keys["d"])
  return send("srb");

 /* STRAIGHT */
 if(keys["w"]||keys["arrowup"])
  return send("f");

 if(keys["s"]||keys["arrowdown"])
  return send("b");

 /* SLIDE */
 if(keys["a"])
  return send("sl");

 if(keys["d"])
  return send("sr");

 /* ROTATE */
 if(keys["q"]||keys["arrowleft"])
  return send("l");

 if(keys["e"]||keys["arrowright"])
  return send("r");

 /* BUZZER HOLD */
 if(keys[" "])
  return send("bz");

 /* STOP */
 send("s");
}

/* ===== INIT ===== */

window.onload=function()
{
 bind("f","f");
 bind("b","b");

 bind("sl","sl");
 bind("sr","sr");

 bind("slf","slf");
 bind("srf","srf");
 bind("slb","slb");
 bind("srb","srb");

 bind("tl","l");
 bind("tr","r");

 bind("buzzer","bz");
}

</script>

</head>

<body>

<h1>AGV Web Controller</h1>
<h2>Wi-Fi AP Mode</h2>

<table cellspacing="10">

<tr>
<td id="slf"><span class="arrows">&#11017;</span></td>
<td id="f"><span class="arrows">&#8679;</span></td>
<td id="srf"><span class="arrows">&#11016;</span></td>
</tr>

<tr>
<td id="sl"><span class="arrows">&#8678;</span></td>
<td id="buzzer"><span class="arrows">&#128266;</span></td>
<td id="sr"><span class="arrows">&#8680;</span></td>
</tr>

<tr>
<td id="slb"><span class="arrows">&#11019;</span></td>
<td id="b"><span class="arrows">&#8681;</span></td>
<td id="srb"><span class="arrows">&#11018;</span></td>
</tr>

<tr>
<td id="tl"><span class="circularArrows">&#8634;</span></td>
<td style="background:transparent; box-shadow:none; border:none;"></td>
<td id="tr"><span class="circularArrows">&#8635;</span></td>
</tr>

</table>

</body>
</html>
)====";

// ================= HANDLERS =================

void handleRoot ()
{
server.send(200,"text/html",page);
}

void cmdF () { forward(0); server.send(200); }
void cmdB () { backward(0); server.send(200); }

void cmdSL () { slide_left(0); server.send(200); }
void cmdSR () { slide_right(0); server.send(200); }

void cmdSLF () { slide_left_forward(0); server.send(200); }
void cmdSRF () { slide_right_forward(0); server.send(200); }

void cmdSLB () { slide_left_backward(0); server.send(200); }
void cmdSRB () { slide_right_backward(0); server.send(200); }

void cmdTL () { turn_left(0); server.send(200); }
void cmdTR () { turn_right(0); server.send(200); }

void cmdS ()
{
stop(0);
digitalWrite(BUZZER_PIN,LOW);   // STOP BUZZER
server.send(200);
}

// ---- HOLD BUZZER ----
void cmdBZ ()
{
digitalWrite(BUZZER_PIN,HIGH);
server.send(200);
}

// ================= SETUP =================

void warcSetup ()
{
Serial.begin(115200);

pinMode(BUZZER_PIN,OUTPUT);
digitalWrite(BUZZER_PIN,LOW);

WiFi.mode(WIFI_AP);
WiFi.softAP(ap_ssid, ap_pass);

server.on("/",handleRoot);

server.on("/f",cmdF);
server.on("/b",cmdB);

server.on("/sl",cmdSL);
server.on("/sr",cmdSR);

server.on("/slf",cmdSLF);
server.on("/srf",cmdSRF);
server.on("/slb",cmdSLB);
server.on("/srb",cmdSRB);

server.on("/l",cmdTL);
server.on("/r",cmdTR);

server.on("/s",cmdS);
server.on("/bz",cmdBZ);

server.begin();
}

void warcLoop ()
{
server.handleClient();
}
