/* 標頭引入檔 */
#include <ansi.h>
/* 偵錯設定 */

#include <net/socket.h>
#include <socket_err.h>

#define PING_TIME 240

#define TELL(x) CHANNEL_D->do_channel(this_object(),"sys",x);
#define COMMAND_SERVER "127.0.0.1 5559"
inherit F_DBASE;

int fd;
private void create_command_channel();
private mixed fun;

/* 檔案主檔 */
void create()
{
        set("channel_id", "指令精靈");
        seteuid(getuid());
#ifdef DEBUG
    TELL(sprintf("[%s]啟始完成。",ctime(time() ) ));
#endif
    call_out((: create_command_channel :),1);
}

private void create_command_channel()
{
  int err;
  fd = socket_create(STREAM, "read_callback","close_socket");
  if ( fd < 0 )
  {
    TELL("連結失敗，可能是主機沒有開啟或是網路無法連線。");
    return;
  }
  err = socket_connect(fd,COMMAND_SERVER,"read_callback","write_callback" );
  if( err != EESUCCESS )
  {
    TELL("連結失敗。");
    fd = -1;
    return ;
  }
  TELL(sprintf("[%s]啟始完成。",ctime(time() ) ));

}
protected void write_callback(int fd) {
    socket_write(fd,"SECURE_PASSWORD\n");
}

protected void read_callback(int fd,mixed message) {
  if(functionp(fun)) {
    evaluate(fun,message);
  }
#ifdef DEBUG
  TELL(message);
#endif
}
void send_command( string cmd , mixed l_fun) {
  // need to be security check
#ifdef DEBUG
  TELL(cmd);
#endif
  socket_write(fd,cmd +"\n");
  fun = l_fun;
}
