# macOS Keylogger

This repository holds the code for a simple and easy to use keylogger for macOS. It is not meant to be malicious, and is written as a proof of concept. There is not a lot of information on keyloggers or implementing them on macOS, and most of the ones I've seen do not work as indicated. This project aims to be a simple implementation on how it can be accomplished on OS X.

> Note: This keylogger is currently unable to capture secure input such as passwords. See issue #3 for more information.

## Usage

Start by cloning the repository and running the proper make commands, shown below. By default, the application installs to `/usr/local/bin/keylogger`, which can easily be changed in the [`Makefile`](https://github.com/caseyscarborough/keylogger/blob/master/Makefile). `make install` may require root access.

```bash
$ git clone https://github.com/caseyscarborough/keylogger && cd keylogger
$ make && make install
```

The application by default logs to `/var/log/keystroke.log`, which may require root access depending on your system's permissions. You can change this in [`keylogger.h`](https://github.com/caseyscarborough/keylogger/blob/master/keylogger.h#L12) if necessary.

```bash
$ keylogger
Logging to: /var/log/keystroke.log
```

If only modifier keys are logging (e.g. in macOS ≥ 10.10), run with root access.

If you'd like the application to run in the background on startup, run the `startup` make target:

```bash
$ sudo make startup
```

To run the application now (note: you will need to run the `sudo make startup` command first):

```bash
$ sudo make load
```

To quit the application now (note: you will need to run the `sudo make startup` command first)::

```bash
$ sudo make unload
```

## Uninstallation

You can completely remove the application from your system (including the startup daemon) by running the following command (logs will not be deleted):

```bash
$ sudo make uninstall
```

### Optional Parameters

You can pass in two optional parameters to the program. The `clear` option will clear the logs at the default location. Any other argument passed in will be used as the path to the log file for that process. See below:

```bash
# Clear the logfile.
$ keylogger clear
Logfile cleared.

# Specify a logfile location.
$ keylogger ~/logfile.txt
Logging to: /Users/Casey/logfile.txt
```

## Issues

### Unable to Create Event Tap

If you get the following error:

```
ERROR: Unable to create event tap.
```

Go into System Preferences and go to Security & Privacy, click the Privacy tab, choose Accessibility in the left pane, and ensure that Terminal is checked.

## Contributing

Feel free to fork the project and submit a pull request with your changes!
