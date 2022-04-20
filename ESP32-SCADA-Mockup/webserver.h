#pragma once
#include "Arduino.h"

String index_html = "<!DOCTYPE html><html><head> <link href=\"https://fonts.googleapis.com/icon?family=Material+Icons\" rel=\"stylesheet\"> <link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css\"> <script src=\"https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/js/materialize.min.js\"></script> <link href=\"https://fonts.googleapis.com/icon?family=Material+Icons\" rel=\"stylesheet\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"/></head><style>body, .main{max-height: 100vh; width: 100%;}input{border: none !important;}</style><body class=\"blue-grey darken-2\"> <div class=\"navbar-fixed\"> <nav> <div class=\"nav-wrapper blue-grey darken-3\" style=\"padding:0 100px;\"> <a href=\"#\" class=\"brand-logo\">Chumbus Controller 6900</a> <ul id=\"nav-mobile\" class=\"right hide-on-med-and-down\"> <li><a href=\"index.html\">Chumbus</a></li><li><a href=\"https://www.hakcat.com\">About</a></li></ul> </div></nav> </div><script>function changeSpeed(){var multiplier=100; var speed=document.getElementById(\"speed\").value; document.getElementById(\"rpm\").innerText=(multiplier*speed) + \" rpms\"; var http=new XMLHttpRequest(); http.open(\"POST\", \"/submit.php\", true); http.setRequestHeader(\"Content-type\", \"application/x-www-form-urlencoded\"); var params=\"speed=\" + speed; http.send(params);}</script> <div class=\"container main gray darken-2\" style=\"padding:1em; margin-top: 2em\"> <h4 style=\"padding-bottom: .5em;\" class=\"white-text\"><i class=\"material-icons\">build</i>&nbsp;&nbsp;Motor Control</h4> <div class=\"card blue-grey darken-3\" style=\"margin-bottom: 5em\"> <div class=\"card-content white-text\"> <form action=\"#\" class=\"speed-slider\"></form> <p class=\"range-field\" style=\"z-index: 100;\" oninput=\"changeSpeed();\"> <input type=\"range\" id=\"speed\" min=\"0\" max=\"255\"/> </p></form> </div></div><div class=\"row\"> <div class=\"col s3\"> <h4 style=\"padding-bottom: .5em;\" class=\"white-text\"><i class=\"material-icons\">timeline</i>&nbsp;&nbsp;Speed</h4> <div class=\"card blue-grey darken-3\" style=\"margin-bottom: 10em\"> <div class=\"card-content white-text\" style=\"text-align: center;\"> <h4 id=\"rpm\">0 rpms</h4> </div></div></div><div class=\"col s3\"> <h4 style=\"padding-bottom: .5em;\" class=\"white-text\"> <i class=\"material-icons\">wifi</i>&nbsp;&nbsp;Status </h4> <div class=\"card blue-grey darken-3\" style=\"margin-bottom: 10em\"> <div class=\"card-content white-text\" style=\"text-align: center;\"> <h4>Connected!</h4> </div></div></div></div></div></body></html>";
