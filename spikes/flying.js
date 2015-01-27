/*
		^
		|
		x
		|
	FL	|	FR
	  \	  /
	   \ /
-------/|\-------y---->
	  / | \
	BL  |   BR
		|
*/


/* Quaternion
	1 := rotation of 180 degrees
	-1 := rotaion of -180 degrees	

*/

var idleMotorSpeeds = [75, 75, 75, 75], // FL, FR, BL, BR
	motorCurrentSpeed = [180, 33, 180, 33], // FL, FR, BL, BR
	targetOrientationVector = [1, 0, 0, 0], // W, X, Y, Z
	oldOrientationVector = [1, 0.5, 0, 0];

var MAX_SPEED = 180;
var MIN_SPEED = 33;
var FULL_SPEED_OFFSET = 0.5;
var MIN_SPEED_OFFSET = -0.5;

function logData(title) {
	console.log(title);
	// console.log(idleMotorSpeeds);
	console.log(motorCurrentSpeed);
	// console.log(targetOrientationVector);
	console.log('====================');
	console.log(' ');
}

function adjustMotorSpeedToTargete(currentOrientationVector) {

	var flMaxOffset = MAX_SPEED - motorCurrentSpeed[0],
		frMaxOffset = MAX_SPEED - motorCurrentSpeed[1],
		blMaxOffset = MAX_SPEED - motorCurrentSpeed[2],
		brMaxOffset = MAX_SPEED - motorCurrentSpeed[3];

	var flMinOffset = motorCurrentSpeed[0] - MIN_SPEED,
		frMinOffset = motorCurrentSpeed[1] - MIN_SPEED,
		blMinOffset = motorCurrentSpeed[2] - MIN_SPEED,
		brMinOffset = motorCurrentSpeed[3] - MIN_SPEED;

	debugger;
	if(currentOrientationVector[1] > 0) {
		deltaOrientationVector = [1, 0, 0, 0]
		deltaOrientationVector[1] = currentOrientationVector[1] - oldOrientationVector[1]
		//we know we're tilted right
		if(deltaOrientationVector[1] > 0) {
			//rotating right		

			// deltaOrientationVector[2] = currentOrientationVector[2] - targetOrientationVector[2];
			// deltaOrientationVector[3] = currentOrientationVector[3] - targetOrientationVector[3];

			if (deltaOrientationVector[1] > 0 && deltaOrientationVector[1] <= FULL_SPEED_OFFSET) {
				// we are rotated to the right
				// decrease speed on left motors, increase on right motors

				motorCurrentSpeed[0] += (flMaxOffset * deltaOrientationVector[1]) / FULL_SPEED_OFFSET;
				motorCurrentSpeed[2] += (blMaxOffset * deltaOrientationVector[1]) / FULL_SPEED_OFFSET;

				motorCurrentSpeed[1] -= (frMinOffset * deltaOrientationVector[1]) / FULL_SPEED_OFFSET;
				motorCurrentSpeed[3] -= (brMinOffset * deltaOrientationVector[1]) / FULL_SPEED_OFFSET;
			}
		} else if (deltaOrientationVector[1] < 0) {
			//rotating left
			if (deltaOrientationVector[1] < 0) {

				//TODO: bollocks .... should slowly go back to idle speeds
				motorCurrentSpeed[0] -= (flMaxOffset * deltaOrientationVector[1]) / FULL_SPEED_OFFSET;
				motorCurrentSpeed[2] -= (blMaxOffset * deltaOrientationVector[1]) / FULL_SPEED_OFFSET;

				motorCurrentSpeed[1] += (frMinOffset * deltaOrientationVector[1]) / FULL_SPEED_OFFSET;
				motorCurrentSpeed[3] += (brMinOffset * deltaOrientationVector[1]) / FULL_SPEED_OFFSET;
			}
		}		
	}
	oldOrientationVector = deltaOrientationVector;
}


// ==== test code ====


logData('initial state');

// adjustMotorSpeedToTargete([1, 0.5, 0.5, 0]);

// logData('after adjustment');

var tmp = [1, 0.5, 0, 0];

setInterval(function() {
	tmp[1] -= 0.01;
	tmp[1] = Math.max(tmp[1], 0);

	adjustMotorSpeedToTargete(tmp);

	logData('~~');
}, 500);