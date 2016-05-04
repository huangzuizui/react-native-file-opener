react-native-file-opener
-
A React Native module that allows you to open a file (mp3, mp4, pdf, word, excel, dwg etc.) on your device with its default application

iOS | Android
------- | ----
<img title="iOS" src="https://github.com/huangzuizui/react-native-file-opener/blob/master/assets/ios_screen.gif"> | <img title="Android" src="https://raw.githubusercontent.com/huangzuizui/react-native-file-opener/master/assets/android_screen.gif">

# Install
##iOS
1. `npm install react-native-file-opener --save`
2. in the XCode's "Project navigator", right click on your project's `Libraries` folder ➜ `Add Files to`
3. Go to `node_modules` ➜ `react-native-file-opener` ➜ `ios` ➜ select `RNFileOpener.xcodeproj`
4. Add `libRNFileOpener.a` to `Build Phases -> Link Binary With Libraries`
5. Compile and have fun

##Android
* `npm install react-native-file-opener --save`
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
* register module
* For react-native below 0.19.0 (use cat ./node_modules/react-native/package.json | grep version)
```java
// file: MainActivity.java
import com.fileopener.FileOpenerPackage;  // <- import

public class MainActivity extends Activity implements DefaultHardwareBackBtnHandler {

  ...

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    mReactRootView = new ReactRootView(this);

    mReactInstanceManager = ReactInstanceManager.builder()
      .setApplication(getApplication())
      .setBundleAssetName("index.android.bundle")
      .setJSMainModuleName("index.android")
      .addPackage(new MainReactPackage())
      .addPackage(new FileOpenerPackage())      // <- add package
      .setUseDeveloperSupport(BuildConfig.DEBUG)
      .setInitialLifecycleState(LifecycleState.RESUMED)
      .build();

    mReactRootView.startReactApplication(mReactInstanceManager, "ExampleRN", null);

    setContentView(mReactRootView);
  }

  ...

}
```
* For react-native 0.19.0 and higher
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
            new MainReactPackage(), //<- Add comma
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
2. Basic usage
```javascript
const FilePath = ...; // path of the file
const FileMimeType = ...; // mime type of the file
FileOpener.open(
    FilePath,
    FileMimeType
).then((msg) => {
    console.log('success!!')
},() => {
    console.log('error!!')
});
```
##Usage with react-native-fs
* You can get filepath by using [react-native-fs](https://github.com/johanneslumpe/react-native-fs)

```javascript
const RNFS = require('react-native-fs');
const FileOpener = require('react-native-file-opener');

const SavePath = Platform.OS === 'ios' ? RNFS.DocumentDirectoryPath : RNFS.ExternalDirectoryPath;
const sampleDocFilePath = SavePath + '/sample.doc';

...

  function openSampleDoc() {
        FileOpener.open(
            sampleDocFilePath,
            'application/msword'
        ).then(() => {
            console.log('success!!');
        },(e) => {
            console.log('error!!');
        });

    }
    
...
```
##Demo project
[https://github.com/huangzuizui/react-native-file-opener-demo](https://github.com/huangzuizui/react-native-file-opener-demo)
