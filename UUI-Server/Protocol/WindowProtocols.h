enum WindowEvent {
  W_RESIZE,
  W_MINIMISE,
  W_MAXIMISE,
  W_CLOSE,
  W_CLOSED
};

struct WindowProtocol {
  uWindow* window;
  WindowEvent event;
  float param0;
  float param1;
  float param2;
  float param3;
};
