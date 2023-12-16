const base_url = "http://localhost:3000";

function login() {
    let userName = document.getElementById("uname").value;
    let passWord = document.getElementById("pass").value;
    let postData =
        '{"username": "' + userName + '", "password": "' + passWord + '" }';

    let url = base_url + "/login";
    let xmlLogin = new XMLHttpRequest();
    xmlLogin.onreadystatechange = function () {
        if (xmlLogin.readyState == 4 && xmlLogin.status == 200) {
            console.log(this.response);
            window.localStorage.setItem("myToken", this.response);
            //lenght of false =5
            if (window.localStorage.getItem("myToken").length == 5) {
                document.getElementById("message").innerHTML =
                    "Wrong username/password";
            } else {
                document.getElementById("message").innerHTML = "Login Success";
            }
        } else {
            document.getElementById("message").innerHTML =
                "Something went wrong";
        }
    };
    xmlLogin.open("POST", url, true);
    xmlLogin.setRequestHeader("Content-Type", "application/json");
    xmlLogin.send(postData);
}
function logout() {
    window.localStorage.clear();
    document.getElementById("message").innerHTML = "You have logged out";
    document.getElementById("allbooks").innerHTML = "";
}

function allBooks() {
    let xmlBooks = new XMLHttpRequest();
    xmlBooks.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            let books = JSON.parse(this.response);
            let row = "<ul>";
            books.map((book) => {
                row +=
                    "<li key=" +
                    book.id_book +
                    ">" +
                    book.name +
                    ", " +
                    book.author +
                    ", " +
                    book.isbn +
                    "</li>";
            });
            row += "</ul>";
            document.getElementById("allbooks").innerHTML = row;
        } else {
            console.log("Can not get data");
        }
    };
    let url = base_url + "/book";
    xmlBooks.open("GET", url);
    xmlBooks.setRequestHeader(
        "Authorization",
        "Bearer " + window.localStorage.getItem("myToken")
    );

    xmlBooks.send();
}

function addBook() {
    let name = document.getElementById("addname").value;
    let author = document.getElementById("addauthor").value;
    let isbn = document.getElementById("addisbn").value;
    let postData =
        '{"name": "' +
        name +
        '", "author": "' +
        author +
        '",  "isbn": "' +
        isbn +
        '" }';

    let xmlBooks = new XMLHttpRequest();
    xmlBooks.onreadystatechange = function () {
        if (xmlBooks.readyState == 4 && xmlBooks.status == 200) {
            document.getElementById("message").innerHTML = "Book added";
            allBooks();
        } else {
            document.getElementById("message").innerHTML =
                "Something went wrong";
        }
    };
    let url = base_url + "/book";
    xmlBooks.open("POST", url, true);
    xmlBooks.setRequestHeader("Content-Type", "application/json");

    xmlBooks.setRequestHeader(
        "Authorization",
        "Bearer " + window.localStorage.getItem("myToken")
    );
    xmlBooks.send(postData);
}
