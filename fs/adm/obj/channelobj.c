#include <login.h>
#include <dbase.h>

inherit F_DBASE;
//inherit F_SAVE;
private void time_out();
private void net_dead();
private int check_magic_word(string arg);
private void input_channel(string arg);
private void input_message(string arg);
private int send_message(string arg);

private string channel;
private string message;
void logon()
{
        call_out( (: time_out :), LOGIN_TIMEOUT );
        if(query_ip_number(this_object()) != "127.0.0.1") 
        {
                call_out( (:time_out:), 0 );
                return ;
        }
        write("magic_word:");
        input_to((: check_magic_word :),0);
        return ;
}
private int check_magic_word(string arg)
{
  if(arg != MAGIC_WORD )
  {
    call_out((:time_out:),0);
    return ;
  }
  write("channel:");
  input_to((:input_channel:),0);
}
private void input_channel(string arg)
{
  channel = arg;
  write("message:");
  input_to((:input_message:),0);
}
private void input_message(string arg)
{
  message = arg;
  write("user data:");
  input_to((:send_message:),0);
}
private int send_message(string arg)
{
  mapping db = restore_variable(arg);
  dbase = db;
  enable_wizard();
  enable_commands();
  add_action("command_hook", "", 1);

  printf("%s:%s:%O:%d",channel,message,db,wizardp(this_object()));
  write(CHANNEL_D->do_channel(this_object(), channel, message));
  return call_out( (:time_out:), 0 );


}
// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
private void net_dead()
{
        remove_call_out("time_out");
        call_out( (:time_out:), 0 );
}

private void time_out()
{
//      printf("auth_ok:0\nend\n");
                                 
        destruct(this_object());
}
/*
// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
        string id;

        id = query("id", 1);
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}
*/
void receive_message(string type, string str)
{
        if( type!= "write" ) return;
        receive(str);
}

void catch_tell(mixed message)
{
        receive(message);
}
/* 只能讀，不能寫入比較安全 */
//int save() {}
