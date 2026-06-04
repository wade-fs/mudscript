// tell.c

#include <ansi.h>
#include <dbase.h>
#include <net/dns.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

int help(object me);

        void create() {seteuid(getuid());}

int main( object me, string arg )
{
        int len;
        string target, msg, mud;
        string stat,id;
        object obj;

        if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
        target = lower_case (target);

        if( sscanf(target, "%s@%s", target, mud)==2 ) {
          // 自己寫一寫又拿掉了
          // if (wizardp (me)) {
                GTELL->send_gtell(mud, target, me, msg);
                write("網路訊息已送出﹐可能要稍候才能得到回應。\n");
                return 1;
          // }
          // else
          //   return notify_fail ("【系統】: 玩家不能用跨網 tell\n");
        }

        obj = find_player(target);
        if( !obj )
        	return notify_fail("沒有這個人...\n");
//asin自己說希望可以關掉tell,所以就幫他關by bss
        	
        if( obj->query("id") == me->query("id") )
        	return notify_fail("自言自語?!\n"); 
        if(!wizardp(me)&&wizardp(obj)&&obj->query("env/no_tell")&&(obj->query("env/invis")||obj->query("env/invis"))) return notify_fail("沒有這個人...\n");

        if(!wizardp(me)&&wizardp(obj)&&wizhood(obj)!="(manager)"&&wizhood(obj)!="(admin)"&&wizhood(obj)!="(arch)")
                return notify_fail("玩家不能對大巫師以下的人用 tell。\n");
        if( obj->query("env/no_tell") && wiz_level(me) <= wiz_level(obj)&&!me->query("env/can_tell_wiz"))
		if( wiz_level(obj) > 1 )
           		return notify_fail("沒有這個人...\n");
          	else if(!me->query("env/can_tell_wiz"))
           		return notify_fail(obj->name()+"現在不想受打擾。\n");
        if( obj->query_temp("netdead") )
          return notify_fail (GRN+ obj->name(1)+"斷線中...\n" + NOR);

        stat = "";
        if( in_input(obj) )
          stat = obj->name(1)+"輸入文字中...\n";
        if( in_edit(obj) )
          stat = "編輯檔案中...\n";
        if( interactive(obj) && query_idle( obj ) > 120 )
          stat = "發呆中...\n";
        if(obj->query("env/mxp"))
          id = ESC+"[6z"+ "<send \"tell &text; \" PROMPT>"+me->query("id") +"</send>"+ESC +"[7z";
        else
          id = me->query("id");

write("『"+HIW+"密談"+NOR+"』" + HBRED+stat + "你用千里傳音告訴" + obj->name(1) +": " + msg+"\n" + NOR); 
tell_object(obj, sprintf("『" + HIW + "密談" + NOR + "』" + HBRED + "%s用千里傳音告訴你: %s\n" + NOR,
                me->name(1)+"("+id+")", msg));
	if( obj->query("away") )
    {
    len=sizeof(obj->query("away"));
		if( obj->query("away")[0..0]=="1" )
		        tell_object( me, sprintf( HBGRN + "%s用千里傳音告訴你: %s\n" + NOR,
                    obj->name(1)+"("+obj->query("id")+")", obj->query("away")[1..len-1] ));

    }
        obj->set_temp("reply", me->query("id"));
        return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
        object ob;

        if( ob = find_player(to) ) {
                if( cname )
                        tell_object(ob, sprintf(HIG + "%s(%s@%s)告訴你﹕%s\n" + NOR,
                                cname, capitalize(from), mud, msg ));
                else
                        tell_object(ob, sprintf(HIG + "%s@%s 告訴你﹕%s\n" + NOR,
                                capitalize(from), mud, msg ));
                ob->set_temp("reply", from + "@" + mud);
                return 1;
        } else
                return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : tell <某人> <訊息>
指令說明 :
           你可以用這個指令和其他地方的使用者說話。
其他參考 :
           reply
HELP
        );
        return 1;
}
