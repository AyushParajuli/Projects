// /* 
// given a vector vec, function returns the magnitude of
// the vector
// */

// function magnitude(vec){
//     let mag = 0.0;
//     vec.forEach(element => {
//         //mag += Math.pow(element, 2);
//         mag += element ** 2;
//     });
//     return Math.sqrt(mag);
// }

// /* 
// given the vector vec, function returns a unit vector
// in the same direction
// */
// function normalize(vec){
//     let unitVec = [];
//     let reciprocalMag = 1/magnitude(vec);
//     vec.forEach(element => {
//         unitVec.push(reciprocalMag * element);
//     });
//     return unitVec;
// }


// /*
// when this function is passed a unit vector and a magnitude
// it will return a vector in the direction of the unitvector
// of length magnitude
// */
// function scaledVector(unitVector, magnitude){
//     let scaledVec = [];
//     unitVector.forEach(element => {
//         scaledVec.push(magnitude * element);
//     });
//     return scaledVec;
// }


// /*
// this function returns an array representing the new position
// of the the turtle.

// This new position is based on:
// original - the original position
// heading - a unit vector representing the heading of the turtle
// amount - representing the number of pixels to move forward by.
// */
// function getNewPosition(original, heading, amount){
//     let newPos = [];
//     let scaleVec = scaledVector(heading, amount);
//     original.forEach((element, index) => {
//         newPos.push(element + scaleVec[index]);
//     });
//     return newPos;
// }


// /*
// this function returns an array reprsenting a unit vector 
// with the heading of the turtle after it rotates amount 
// degrees counter clockwise (turning left)

// This new heading vector is based on:
// heading - the original heading of the turtle
// amount - the number of degrees to turn
// */
// function turnLeft(heading, amount){
//     let theta = amount * Math.PI / 180;
//     let xHead = heading[0];
//     let yHead = heading[1];
//     let xRotate = (xHead * Math.cos(theta)) - (yHead * Math.sin(theta));
//     let yRotate = (xHead * Math.sin(theta)) + (yHead * Math.cos(theta));
//     return [xRotate, yRotate];
// }



// /*
// this function returns an array reprsenting a unit vector 
// with the heading of the turtle after it rotates amount 
// degrees clockwise (turning right)

// This new heading vector is based on:
// heading - the original heading of the turtle
// amount - the number of degrees to turn
// */
// function turnRight(heading, amount){
//     let theta = amount * Math.PI / 180;
//     let xHead = heading[0];
//     let yHead = heading[1];
//     let xRotate = (xHead * Math.cos(theta)) + (yHead * Math.sin(theta));
//     let yRotate = -(xHead * Math.sin(theta)) + (yHead * Math.cos(theta));
//     return [xRotate, yRotate];
// }


function getVectorMagnitude(vec) {
  let mag = 0.0;
  for (let i = 0; i < vec.length; i++) {
    mag += vec[i] ** 2;
  }
  return Math.sqrt(mag);
}

/* 
given the vector vec, function returns a unit vector
in the same direction
*/
function getUnitVector(vec) {
  let unitVec = [];
  const mag = getVectorMagnitude(vec);
  const reciprocalMag = 1 / mag;
  for (let i = 0; i < vec.length; i++) {
    unitVec.push(reciprocalMag * vec[i]);
  }
  return unitVec;
}



/*
when this function is passed a unit vector and a magnitude
it will return a vector in the direction of the unitvector
of length magnitude
*/
function getVectorScaledByMagnitude(unitVector, magnitude) { 
  let scaledVector = [];
  for (let i = 0; i < unitVector.length; i++) {
    scaledVector.push(magnitude * unitVector[i]);
  }
  return scaledVector;
}


/*
this function returns an array representing the new position
of the the turtle.
*/
function getNewPosition(original, heading, amount) {
  let newPosition = [];
  let scaleVec = getVectorScaledByMagnitude(heading, amount);
  for (let i = 0; i < original.length; i++) {
    newPosition.push(original[i] + scaleVec[i]);
  }
  return newPosition;
}



/*
this function returns an array representing a unit vector 
with the heading of the turtle after it rotates amount 
degrees counter clockwise (turning left)
*/
function turnLeft(heading, amount) {
  const [x, y] = heading;
  const theta = amount * Math.PI / 180;
  const sinTheta = Math.sin(theta);
  const cosTheta = Math.cos(theta);
  const newX = x * cosTheta - y * sinTheta;
  const newY = x * sinTheta + y * cosTheta;
  return [newX, newY];
}

/*
this function returns an array representing a unit vector 
with the heading of the turtle after it rotates amount 
degrees clockwise (turning right)
*/
function turnRight(heading, amount) {
  const [x, y] = heading;
  const theta = amount * Math.PI / 180;
  const sinTheta = Math.sin(theta);
  const cosTheta = Math.cos(theta);
  const newX = x * cosTheta + y * sinTheta;
  const newY = -x * sinTheta + y * cosTheta;
  return [newX, newY];
}
