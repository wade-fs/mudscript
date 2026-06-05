// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, mud,id;
	object obj;

	if( !arg || arg=="" )
		return notify_fail("你要回答什麼﹖\n");

	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("剛才沒有人和你說過話。\n");

        target = lower_case (target);
	if( sscanf(target, "%s@%s", target, mud)==2 ) {
                write ("[test]: "+ target + "@" + mud + ": " + arg + "\n");
		GTELL->send_gtell(mud, target, me, arg);
		write("網路訊息已送出﹐可能要稍候才能得到回應。\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("剛才和你說話的人現在無法聽見你﹐或者已經離開遊戲了。\n");
    if(target=="cgy"&&obj->query("env/no_tell"))
	    return notify_fail("剛才和你說話的人現在無法聽見你﹐或者已經離開遊戲了。\n");
     if ((obj->gage(me) || obj->query("env/no_tell")) && wiz_level(obj) > wiz_level(me))
                return notify_fail(obj->name()+"現在不想受打擾。\n");
  if(obj->query("env/mxp"))
    id = ESC+"[6z"+ "<send \"tell &text; \" PROMPT>"+me->query("id") +"</send>"+ESC +"[7z";
  else
    id = me->query("id");

	write( HBRED + "你用千里傳音回答" + obj->name(1) + "﹕" + arg + "\n" + NOR);
	tell_object(obj, sprintf( HBRED + "%s(%s)用千里傳音回答你﹕%s\n" + NOR,
		me->name(1), id , arg ));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : reply <訊息>
指令說明 :
           這個指令用來回答剛才用 tell 和你說話的使用者。
其他指令 :
           tell，say
HELP
	);
	return 1;
}
