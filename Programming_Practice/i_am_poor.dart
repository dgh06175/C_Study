import 'package:flutter/material.dart';

void main() {
  runApp(
    MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.grey[400],
        appBar: AppBar(
          backgroundColor: Colors.grey[800],
          title: Center(
            child: Text('I am Poor'),
          ),
        ),
        body: Center(
          child: Image(
            image: AssetImage('images/fogg-156.png'),
          ),
        ),
      ),
    ),
  );
}
