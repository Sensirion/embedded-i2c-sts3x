# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).


## [Unreleased]

## [2.0.0] - 2023-11-14

### CHANGED

- Remove usage of float.
  sht3x_measure_single_shot and sht3x_blocking_read_measurement now return a int32_t,
  conversion from ticks to physical value uses an approximation and the returned
  temperature is in milli degrees celsius and humidity in milli %.


## [1.0.0] - 2023-10-27

Initial release

[unreleased] https://github.com/Sensirion/embedded-i2c-sts3x/compare/2.0.0...HEAD
[2.0.0] https://github.com/Sensirion/embedded-i2c-sts3x/compare/1.0.0...2.0.0
[1.0.0] https://github.com/Sensirion/embedded-i2c-sts3x/releases/tag/1.0.0