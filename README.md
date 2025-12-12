# Setup

If you do not have GNU GCC, bits/stdc++.h will not be a valid header. Create a bits/stdc++.h file with the contents of [this](https://gist.github.com/goldfish088/88ff085b9251d4aa20a65a7f4ba37216) gist, and symlink this into your cpp include path.

This should suffice: `sudo ln -s "$(pwd)/bits$ "$CPP_INCLUDE/bits"`

Note: this is a hack, so precompiling stdc++.h will not work on non-gcc compilers (since only it provides libstdc++).
Will run into errors similar to below:
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/bits/stdc++.h:34:12: fatal error: 'cassert' file not found
   34 |   #include <cassert>
      |            ^~~~~~~~~
1 error generated.

Otherwise, follow [this guide](https://usaco.guide/general/running-code-locally?lang=cpp#precompiling-bitsstdch) for precompiling the header.