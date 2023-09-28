/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <memory>
#include <string>

#if defined(__PROSPERO__)
extern "C" {
    void inet_ntoa() {}
    void gethostbyname() {}
    void getservbyname() {}
    int ioctl(int, unsigned long, ...) { return 0; }
    void fcntl_shim() {}
    void read_system_certificates_NP() {
        //int a = 0;
    }
    void getenv() {}
    void gmtime_r() {}
    void random_generate_number_NP() {
        //int a = 0;
    }
    int h_errno;
}
#endif

#include <grpcpp/grpcpp.h>

#include "greeter.grpc.pb.h"

class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<grpc::Channel> channel)
      : stub_(Greeter::GreeterService::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string SayHello(const std::string& user) {
    // Data we are sending to the server.
    Greeter::HelloRequest request;
    request.set_name(user);

    // Container for the data we expect from the server.
    Greeter::HelloResponse response;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    grpc::ClientContext context;

    // The actual RPC.
    grpc::Status status = stub_->Hello(&context, request, &response);

    // Act upon its status.
    if (status.ok()) {
      return response.reply_message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<Greeter::GreeterService::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  std::string target_str;
  std::string arg_str("--target");
  if (argc > 1) {
    std::string arg_val = argv[1];
    size_t start_pos = arg_val.find(arg_str);
    if (start_pos != std::string::npos) {
      start_pos += arg_str.size();
      if (arg_val[start_pos] == '=') {
        target_str = arg_val.substr(start_pos + 1);
      } else {
        std::cout << "The only correct argument syntax is --target="
                  << std::endl;
        return 0;
      }
    } else {
      std::cout << "The only acceptable argument is --target=" << std::endl;
      return 0;
    }
  } else {
      //target_str = "grpc.thecodeway.com:5050";
      target_str = "localhost:5050";
  }

#if 0
  const char* g_server_crt =
      "-----BEGIN CERTIFICATE-----\n"
      "MIIDZTCCAk2gAwIBAgIJAOFO3+DpMNlLMA0GCSqGSIb3DQEBCwUAMEsxCzAJBgNV\n"
      "BAYTAkNOMRAwDgYDVQQHDAdCZWlqaW5nMRIwEAYDVQQKDAlUdXJib0xpbmsxFjAU\n"
      "BgNVBAMMDXR1cmJvbGluay5kZXYwHhcNMjIxMjA5MTQwNjI4WhcNMzIxMjA2MTQw\n"
      "NjI4WjBLMQswCQYDVQQGEwJDTjEQMA4GA1UEBwwHQmVpamluZzESMBAGA1UECgwJ\n"
      "dHVyYm9saW5rMRYwFAYDVQQDDA10dXJib2xpbmsuZGV2MIIBIjANBgkqhkiG9w0B\n"
      "AQEFAAOCAQ8AMIIBCgKCAQEAr8vdbsXtLWOEWoygSluR3BtYJcp+1nbDwrytr7WX\n"
      "XcnzSB1rQ0lt3yQmQ5BKm6CLbUeKtQd7fIUT1JRn3KJ/dSHXT4qEWWO0XJLJeoAI\n"
      "FXprLWolbrBA8QCAs8Hcbm8F/efHphKU4a10HhD6ENa4YqYPnd89vfYgSPGS/UmF\n"
      "ojWicWjmmT7Np5PBo81mzpbyhGTlOeZj6LLp77w8772MRBDZTn4eDXDuCdfbs2HM\n"
      "YFK4OQ2QQjrh2LSCA6VQgi8gGaXtp2k8CwVlXQpOFWmYX0FyXX/4qvkvXl8rG07T\n"
      "AvX7iCaG3owAYrDeQUL7NqbTvAMHiqivCwrFzThNq+XSkQIDAQABo0wwSjBIBgNV\n"
      "HREEQTA/gg8qLnR1cmJvbGluay5kZXaCECoudGhlY29kZXdheS5jb22CDyoubGV5\n"
      "b3V0ZWNoLm5ldIIJbG9jYWxob3N0MA0GCSqGSIb3DQEBCwUAA4IBAQCUlziOgdSF\n"
      "+GrN2PxrZmRP9bhbLEc1GAWGzStN4xsZFcPIesrDbf74tua65idKvSL4vyx6lpPb\n"
      "ino6mwIgP8ZUV3jdkgKTUMzeqJJY8hoH5Sza93kOZX0oDFyuEJ7LS9kPrLIqEkdp\n"
      "Myc690q5GqNLdSWZqONjAp1S3dezQoKRV/YC6PqMr+1Dq/oRIz83NYWan0vpnHFC\n"
      "gRlK5Rb37ueI+Pe+d6Wg9JSwdo0mFJ5hGfT5Ler4AoA9HMss1k9lJ18iFoSyBCcn\n"
      "wIg5gcxJe6P7DKXnOknt1Sa0Us/li8ux5J8bVgqImkqx2nagDugcW0BfQYcoFilH\n"
      "pgulZBZZCO3S\n"
      "-----END CERTIFICATE-----\n";
  grpc::SslCredentialsOptions ssl_opts;
  ssl_opts.pem_root_certs = g_server_crt;
  std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(target_str, grpc::SslCredentials(ssl_opts));
#else
  std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials());
#endif
  GreeterClient greeter(channel);
  std::string user("world");
  std::string reply = greeter.SayHello(user);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
