<?php
	namespace picopter\php;

	error_reporting(E_ALL);

	require_once '/home/pi/thrift-0.9.0/lib/php/lib/Thrift/ClassLoader/ThriftClassLoader.php';

	use Thrift\ClassLoader\ThriftClassLoader;

	$GEN_DIR = '/home/pi/git/picopter/www-waypoints/gen-php';
	
	$loader = new ThriftClassLoader();
	$loader->registerNamespace('Thrift', '/home/pi/thrift-0.9.0/lib/php/lib');
	$loader->registerDefinition('picopter', $GEN_DIR);
	$loader->register();

	use Thrift\Protocol\TBinaryProtocol;
	use Thrift\Transport\TSocket;
	use Thrift\Transport\THttpClient;
	use Thrift\Transport\TBufferedTransport;
	use Thrift\Exception\TException;

	try {
		$socket = new TSocket('localhost', 9090);
		$transport = new TBufferedTransport($socket, 1024, 1024);
		$protocol = new TBinaryProtocol($transport);
		$client = new \picopter\webInterfaceClient($protocol);
		
		$transport->open();
		
		/* ***************************************** */
		
		include('ajax-functions.php');
		
		/* ***************************************** */
		
		$transport->close();
		
	} catch (TException $tx) {
		//print 'TException: '.$tx->getMessage()."\n";
		print "Error connecting to flight program.";
	}
?>
