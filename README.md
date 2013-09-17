# Mac OS X Keylogger

This repository holds the code for a simple and easy to use keylogger for Mac OS X. It is not meant to be malicious, and is written as a proof of concept. There is not a lot of information on keyloggers or implementing them on Mac OS X, and most of the ones I've seen do not work as indicated. This project aims to be a simple implementation on how it can be accomplished on OS X.

## Usage

Start by cloning the repository and running the proper make commands, shown below. By default, the application installs to `/usr/local/bin/keylogger`.

```bash
$ git clone https://github.com/caseyscarborough/keylog && cd keylog
$ make
$ make install
```

The application by default logs to `/var/log/keystroke.log`, which may require root access depending on your system's permissions. You can change this in [`keylogger.h`](https://github.com/caseyscarborough/keylog/blob/master/keylogger.h#L14) if necessary.

```bash
$ sudo keylogger
Logging to: /var/log/keystroke.log
```

## Contributing

Feel free to fork the project and submit a pull request with your changes!