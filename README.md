<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <h1>Weather Monitoring System</h1>
    <p>This repository contains an Arduino sketch for a weather monitoring system. The system utilizes various sensors to measure temperature, humidity, pressure, and rain status. The data is displayed on an LCD screen and uses LEDs to indicate the weather conditions.</p>
    <h2>Table of Contents</h2>
    <ul>
        <li><a href="#dependencies">Dependencies</a></li>
        <li><a href="#hardware-setup">Hardware Setup</a></li>
        <li><a href="#configuration">Configuration</a></li>
        <li><a href="#usage">Usage</a></li>
        <li><a href="#license">License</a></li>
    </ul>
    <h2 id="dependencies">Dependencies</h2>
    <p>The following libraries are used in this project:</p>
    <ul>
        <li><a href="https://github.com/PaulStoffregen/OneWire">OneWire</a></li>
        <li><a href="https://github.com/milesburton/Arduino-Temperature-Control-Library">DallasTemperature</a></li>
        <!-- Add other library links as needed -->
    </ul>
    <p>Make sure to install these libraries in your Arduino IDE before uploading the sketch to your Arduino board.</p>
    <h2 id="hardware-setup">Hardware Setup</h2>
    <p>Connect the sensors and components to your Arduino board according to the following pin configuration:</p>
    <!-- Add your hardware setup details here -->
    <h2 id="configuration">Configuration</h2>
    <p>Adjust the following configuration variables in the sketch as needed:</p>
    <pre>
#define ALTITUDE 6.7  // Set your altitude for accurate pressure readings
    </pre>
    <h2 id="usage">Usage</h2>
    <ol>
        <li>Upload the sketch to your Arduino board.</li>
        <li>Connect the sensors and components as per the hardware setup.</li>
        <li>Power on the Arduino.</li>
        <li>The system will continuously monitor weather conditions and display them on the LCD screen.</li>
    </ol>
</body>
</html>
