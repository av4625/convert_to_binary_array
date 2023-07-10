# Instructions
* Create a html file `test.html`
* Minify the HTML, CSS and JavaScript:
    * [All in One](https://www.toptal.com/developers/html-minifier) (This doesn't make it as small as doing HTML and JavaScript separate)
        * Doesn't make it as small as possible, pass through HTML below after
    * [HTML](https://kangax.github.io/html-minifier/)
    * [CSS](https://www.toptal.com/developers/cssminifier)
    * [JavaScript](https://www.toptal.com/developers/javascript-minifier)
* Gzip the html file `gzip -c test.html > test.gz`
* Compile the code `clang++ -std=c++17 convert_file_to_binary.cpp`
* Run the code `./a.out test.gz`

# Usage
This is useful for storing webpafges etc in memory for micro controllers. A
typical use case would be for ESPAsyncWebServer. The webpage can be saved like:
```c++
const uint8_t webpage[] PROGMEM = {
    31, 139, 8, 8, 198, 108, 172, 100, 0, 3, ...
};
```
