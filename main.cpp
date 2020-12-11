#include <iostream>

using namespace std;

int install() {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    system("geth-windows-386-1.9.19-3e064192.exe");
    //define something for Windows (32-bit and 64-bit, this part is common)
#ifdef _WIN64
      //define something for Windows (64-bit only)
#else
      //define something for Windows (32-bit only)
#endif


#elif __APPLE__

#include <TargetConditionals.h>

    system("ls");

//    Step 1: Install ethereum
//    system("/bin/bash -c \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)\"");
//    system("brew tap ethereum/ethereum");
//    system("brew install ethereum");
//    system("brew tap ethereum/ethereum");

//    Step 2: Create directory structure

    system("mkdir /Users/$(whoami)/DappsChain");
    system("cp Genesis.json /Users/$(whoami)/DappsChain");
//    system("echo \"{\n"
//           "  \"config\": {\n"
//           "    \"chainId\": 13936,\n"
//           "    \"homesteadBlock\": 0,\n"
//           "    \"eip155Block\": 0,\n"
//           "    \"eip150Block\": 0,\n"
//           "    \"eip158Block\": 0,\n"
//           "    \"byzantiumBlock\": 0\n"
//           "  },\n"
//           "  \"difficulty\": \"400\",\n"
//           "  \"coinbase\": \"100000000000000000\",\n"
//           "  \"timestamp\": \"0x00\",\n"
//           "  \"parentHash\": \"0x0000000000000000000000000000000000000000000000000000000000000000\",\n"
//           "  \"gasLimit\": \"6721975\",\n"
//           "  \"gasPrice\": \"20000000000\",\n"
//           "  \"alloc\": {\n"
//           "    \"0x32d31e8060f7a1255226988b1f522da0112ac59f\": {\n"
//           "      \"balance\": \"100000000000000000000000\"\n"
//           "    },\n"
//           "    \"0x309e41736fd1d33b92bc4063ef16853d6afff6cb\": {\n"
//           "      \"balance\": \"100000000000000000000000\"\n"
//           "    }\n"
//           "  }\n"
//           "}\" > /Users/$(whoami)/DappsChain/Genesis.json");
    system("mkdir /Users/$(whoami)/DappsChain/myDataDir");

//    Step 3: Create the accounts

//    Step 6: Running a Bootnode


// //    system("geth --datadir /Users/$(whoami)/DappsChain/myDataDir init /Users/$(whoami)/DappsChain/Genesis.json");
    system("geth --rpc --rpcaddr 0.0.0.0 --rpcport 8545 --ws --wsport 8546 --datadir /Users/$(whoami)/DappsChain/myDataDir --port 30303 --rpcapi \"db,eth,net,web3\" --networkid 13936 init /Users/$(whoami)/DappsChain/Genesis.json");
// //    system("geth --datadir /Users/$(whoami)/DappsChain/myDataDir --networkid 13936 --rpc --rpcaddr 0.0.0.0 --rpcport 8546");
    system("geth --rpc --rpcport 8545 --datadir /Users/$(whoami)/DappsChain/myDataDir --port 30303 --rpcapi \"db,eth,net,web3\" --networkid 13936 console 2>> /Users/$(whoami)/DappsChain/dappsChain.log");
// //   system("open -a Terminal /Users/$(whoami)/DappsChain");


#if TARGET_IPHONE_SIMULATOR
    // iOS Simulator
#elif TARGET_OS_IPHONE
    // iOS device
#elif TARGET_OS_MAC
    // Other kinds of Mac OS
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
    system("sudo add-apt-repository -y ppa:ethereum/ethereum");
    // linux
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif
    return 0;
}

int main() {
    std::cout << "installing geth" << std::endl;
    int result = install();

    return 0;
}
