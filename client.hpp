#ifndef CLIENT_HPP
#define CLIENT_HPP
#include "exception.hpp"
#include "packet.hpp" // Include your WhiteboardPacket class
#include <boost/asio.hpp>
#include <cstdint>
#include <queue>
using namespace std;

using boost::asio::ip::tcp;

class WhiteboardClient {
private:
  uint32_t version = 1;
  uint32_t user_id;
  string whiteboard_id;
  uint32_t packet_counter = 0;
  boost::asio::io_context io_context;
  tcp::resolver resolver;
  tcp::socket socket;
  // boost::asio::streambuf receive_buffer;
  bool connected_;
  // char receive_buffer_[1024];
  std::unordered_map<uint32_t, WhiteboardPacketType> send_queue;

  boost::asio::ip::tcp::resolver::iterator iter;

public:
  std::queue<WhiteboardPacket> received_queue;
  WhiteboardClient(const std::string &server_ip, unsigned short port)
      : io_context(), resolver(io_context), socket(io_context),
        connected_(false), send_queue() {
#ifndef NDEBUG
    DEBUG_MSG;
#endif
    iter = resolver.resolve(server_ip, std::to_string(port));

    boost::system::error_code error;
    boost::asio::connect(socket, iter, error);
    if (error) {
      // Handle connection error
      std::cerr << "Error connecting "
                   "to server: "
                << error.message() << std::endl;
    }
  }

  ~WhiteboardClient() {
    close(); // Gracefully close connection in destructor
  }

  void send_packet(const WhiteboardPacket &packet);
  void send_create_whiteboard_request();
  void send_create_session_request();
  void send_join_session_request(string _whiteboard_id);
  void send_quit_session_request();
  void send_add_element_request(WhiteboardElements _ele);
  void send_login_request(string username, string password);
  void send_register_request(string username, string password);
  bool handle_receive();
  void handle_receive_async();
  void handle_single_packet(const boost::system::error_code &error,
                            boost::asio::streambuf &buffer);
  void handle_connect(const boost::system::error_code &error);
  protobuf::whiteboardPacket parse_packet(boost::asio::streambuf *buffer);
  void handle_action_response(const protobuf::whiteboardPacket &response);
  void handle_temp_id_response(const protobuf::whiteboardPacket &response);
  vector<WhiteboardElements>
  handle_broadcast(const protobuf::whiteboardPacket &response);
  // void start(const std::string &server_ip, unsigned short port);
  void close();
};
#endif
