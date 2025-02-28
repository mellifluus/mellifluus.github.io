history.scrollRestoration = "manual";
window.onbeforeunload = function () {
    window.scrollTo(0, 0);
}

var i = 0;
const txt = 'Flows like honey.';
const speed = 50;

function typeWriter() {
    if (i < txt.length) {
        document.getElementById("hero").innerHTML += txt.charAt(i);
        i++;
        setTimeout(typeWriter, speed);
    }
}

// setInterval()
setTimeout(typeWriter, 1000);