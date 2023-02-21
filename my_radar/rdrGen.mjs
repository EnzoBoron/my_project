/**======================
 * ?        ABOUT
 * @author    : @nicojqn
 * @createdOn : rdrGenerator for my_radar
 * @desc      : This script generates a radar file for my_radar
 * @howToUse  : node rdrGen.mjs
 *========================**/

import process from 'process';
import fs from 'fs';

const help = () => {
    console.log(`My_Radar RDR Generator
Usage node rdrGen.mjs [planeNumber] [towerNumber] [file] [param]\n
Options:\n
planeNumber:\t Number of planes to generate
towerNumber:\t Number of towers to generate
file:\t\t PathName of the file to generate\n
Param:\n
-h:\t\t Display this help message
-o:\t\t Overwrite the file if it already exists`);
}

const validateParam = () => {
    if (process.argv.includes('-h')) {
        help();
        process.exit(0);
    }
    if (process.argv.length < 5) {
        console.log('Invalid parameters');
        help();
        process.exit(84);
    }
    if (isNaN(process.argv[2]) || isNaN(process.argv[3])) {
        console.log('Invalid parameters');
        help();
        process.exit(84);
    }
    if (process.argv[2] < 0 || process.argv[3] < 0) {
        console.log('Invalid parameters');
        help();
        process.exit(84);
    }
    if (fs.existsSync(process.argv[4]) && !process.argv.includes('-o')) {
        console.log('File already exists');
        process.exit(84);
    }
}

const rdm = (min, max) => {
    return Math.floor(Math.random() * (max - min + 1) + min)
}

const generatePlane = () => {
    const plane = {
        dx: rdm(0, 1920),
        dy: rdm(0, 1080),
        ax: rdm(0, 1950),
        ay: rdm(0, 1100),
        speed: rdm(1, 1),
        delay: rdm(0, 3)
    };
    return plane;
}

const generateTower = () => {
    const tower = {
        x: rdm(0, 1920),
        y: rdm(0, 1080),
        radius: rdm(1, 40),
    };
    return tower;
}

validateParam();

const planeNumber = parseInt(process.argv[2]);
const towerNumber = parseInt(process.argv[3]);
const file = process.argv[4];
let fd;

if (process.argv.includes('-o')){
    fs.unlinkSync(file);
}

fd = fs.openSync(file, 'w');

if (fd === -1) {
    console.log('Error while creating file');
    process.exit(84);
}

const planes = [];
const towers = [];

for (let i = 0; i < planeNumber; i++) {
    planes.push(generatePlane());
}

for (let i = 0; i < towerNumber; i++) {
    towers.push(generateTower());
}

while (planes.length + towers.length != 0) {
    let rand = Math.floor(Math.random() * 10000 % 2);
    if (planes.length == 0)
        rand = 1;
    if (towers.length == 0)
        rand = 0;
    if (rand === 0 && planes.length > 0) {
        fs.appendFileSync(file,
            `A ${planes[0].dx} ${planes[0].dy} ${planes[0].ax} ${planes[0].ay} ${planes[0].speed} ${planes[0].delay}`);
        planes.shift();
    }
    if (rand === 1 && towers.length > 0) {
        fs.appendFileSync(file,
            `T ${towers[0].x} ${towers[0].y} ${towers[0].radius}`);
        towers.shift();
    }
    if (planes.length + towers.length != 0)
        fs.appendFileSync(file, '\n');
}

fs.closeSync(fd);

console.log('File generated successfully\n');
console.log(`Planes: ${planeNumber}
Towers: ${towerNumber}
File: ${file}\n
Good luck!`);