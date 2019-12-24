# qt_multiple_tabbar_widget
A simple widget that allows you create multiple tabbar from a few QTabBars

## How to use

Just create `MultipleRowsTabBar` class entity and than add new tabs by its rows.

### Example

```
MultipleRowsTabBar *multiTab = new MultipleRowsTabBar(2, this);

multiTab->addTab(0, QIcon(":/images/plug-connect.png"), tr("COM"), _comConfWidget);
multiTab->addTab(0, QIcon(":/images/network-ip-local.png"), tr("IP"), _ipConfWidget);
multiTab->addTab(0, QIcon(":/images/ScalesTerminal.png"), tr("Scales"), _scalesConf);
multiTab->addTab(0, QIcon(":/images/surveillance-camera.png"), tr("Cams"), _camConf);
multiTab->addTab(1, QIcon(":/images/gear_16.png"), tr("ICPCON"), _autoWidget);
multiTab->addTab(1, QIcon(":/images/RemoteDisplay.png"), tr("Digit table"), _digitConf);
multiTab->addTab(1, QIcon(":/images/RfidReader.png"), tr("RFID"), _rfidWidget);
multiTab->addTab(1, QIcon(":/images/barcode-2d.png"), tr("QR"), _qrWidget);
```

[Example image](https://sun9-27.userapi.com/c205628/v205628501/1be05/4l_7HmN4VVE.jpg)
