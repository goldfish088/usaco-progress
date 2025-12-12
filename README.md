# Setup

If you do not have GNU GCC, bits/stdc++.h will not be a valid header. Create a bits/stdc++.h file with the contents of [this](https://gist.github.com/goldfish088/88ff085b9251d4aa20a65a7f4ba37216) gist, and symlink this into your cpp include path.

This should suffice: `sudo ln -s "$(pwd)/bits$ "$CPP_INCLUDE/bits"`