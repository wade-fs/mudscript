#include <ansi.h>
#define INTERMAIL "/data/mailo"

inherit F_CLEAN_UP;
 
int help (object);

void done_mail (object me, string who, string str)
{
  string	*msg;
  int		i;

  write_file (INTERMAIL, "#mailto: "+who+"\n");
  write_file (INTERMAIL, sprintf (@BASIC_MSG
--> 嗨! %s, 這是一封來自網路上的多人遊戲站來的信,
--> 該站位於 telnet 140.122.77.123 4000, 歡迎您前往參觀, 此信是由該
--> 站上的 %s(%s) 寄來的, 如果您要回信, 請在信的第一行寫:
--> #mailto: %s
BASIC_MSG
, who, me->name(), me->query ("id"),  me->query ("id")));

  msg = explode (str, "\n");
  for (i=0; i<sizeof (msg); i++)
    if (msg[i][0..7] == "#mailto:")
      msg[i] = ">"+msg[i];
  str = implode (msg, "\n");
  write_file (INTERMAIL, str);
  tell_object (me, "好了, 理論上信寄出去了.\n");
}

int main(object me, string arg)
{
  seteuid(getuid(me));
 
  if (!arg) return help (me);

  write ("請輸入你要寄的內容.\n");
  me->edit ( (: done_mail, me, arg :) );
  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : email e-mail-address
指令說明 :

  mud --> internet
  ================
  email jjchen@ice.ntnu.edu.tw  <-- 就開始進入編輯模式，跟 post 一樣.

  internet --> mud
  ================
  當然是在 internet 上，如工作站帳號下，或 linux 下。
  必須在第一行寫上 #mailto: WHO  <-- WHO 是在 mud 中的 id。如:
#mailto: wade                    <-- 必須從第一格開始些喔。
  假設現在是在工作站帳號下，而且你會用 mail 指令寄信，
  要寄到 mud 通通是寄給 jjchen@ice.ntnu.edu.tw，那就是狂想的菠蘿麵包。即:
  mail jjchen@ice.ntnu.edu.tw    <-- 按句點即可以結束。

其他參考 :
           post, mail(請到郵局使用)
HELP
    );
    return 1;
}
