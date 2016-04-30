react-native-file-opener
-
A React Native module that allows you to open a file (mp3, mp4, pdf, word, excel, dwg etc.) on your device with its default application
# Install
##iOS
1. `npm install react-native-file-opener --save`
2. in the XCode's "Project navigator", right click on your project's `Libraries` folder ➜ `Add Files to`
3. Go to `node_modules` ➜ `react-native-file-opener` ➜ `ios` ➜ select `RNFileOpener.xcodeproj`
4. Add `libRNFileOpener.a` to `Build Phases -> Link Binary With Libraries`
5. Compile and have fun

##Android
1. `npm install react-native-file-opener --save`
```java
// file: android/settings.gradle
...
include ':react-native-file-opener'
project(':react-native-file-opener').projectDir = new File(settingsDir, '../node_modules/react-native-file-opener/android')
```

```java
// file: android/app/build.gradle
...
dependencies {
		...
		compile project(':react-native-file-opener')
}
```
```java
// file: MainActivity.java
	...
import com.fileopener.FileOpenerPackage;//<- import package

public class MainActivity extends ReactActivity {

   /**
   * A list of packages used by the app. If the app uses additional views
   * or modules besides the default ones, add more packages here.
   */
    @Override
    protected List<ReactPackage> getPackages() {
        return Arrays.<ReactPackage>asList(
            new MainReactPackage(),
            new FileOpenerPackage() //<- Add package
        );
    }
...
}
```

##Usage
1. In your React Native javascript code, bring in the native module
```javascript
const FileOpener = require('react-native-file-opener');
```
2. Basic ussage
```javascript
const FilePath = ...; // path of the file
const FileMimeType = ...; // mime type of the
FileOpener.open(
    FilePath,
    FileMimeType
).then((msg) => {
    console.log('success!!')
},() => {
    console.log('error!!')
});
```
