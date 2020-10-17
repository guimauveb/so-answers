var sliders = {};

(function () {

    var CSRFToken;

    this.setCSRFToken = function(t) {
        CSRFToken = t;
    }

    this.updateMotorValue = async function (motor, value) {
        try {
            const response = await fetch("/updateMotorValue", {
                method: 'POST',
                mode: 'cors',
                cache: 'no-cache',
                credentials: 'same-origin',
                headers: {
                    'Accept': 'application/json, text/plain, */*',
                    'Content-Type': 'application/json',
                    'X-CSRFToken': CSRFToken
                },
                body: JSON.stringify({"motor": motor, "value": value})
            })
            console.log(await response.json());
        } catch(err) {
            console.log(err);
        }
    };

}).apply(sliders);
