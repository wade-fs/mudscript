// ask.c

#include <ansi.h>
inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$n搖搖頭﹐說道﹕沒聽說過。\n",
	"$n睜大眼睛望著$N﹐顯然不知道$P在說什麼。\n",
	"$n聳了聳肩﹐很抱歉地說﹕無可奉告。\n",
	"$n說道﹕嗯....這我可不清楚﹐你最好問問別人吧。\n",
	"$n想了一會兒﹐說道﹕對不起﹐你問的事我實在沒有印象。\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
	mapping inquiry;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要問誰什麼事﹖\n");
	dest = lower_case(dest);

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("這裡沒有這個人。\n");

	if( !ob->is_character() )
		return notify_fail ("你面對著"+ob->name()+"喃喃自語....\n");
	if( ob->query("no_answer") )
		return 0;

	if (!ob->query("can_speak"))
		return notify_fail ("你問話的對象顯然聽不懂你的話.\n");

	if( userp(ob) ) return 1;

	if( !living(ob) ) {
		message_vision(dest+"但是很顯然的﹐$n現在的狀況沒有辦法給$N任何答覆。\n",
			me, ob);
		return 1;
	}

	// by babe 傳回 "" 便不說話
	if( stringp( msg = ob->query("inquiry/" + topic ) ) )
		if( msg=="" )
			return 1;
		else {
       	        	message_vision( CYN "$n說道﹕" + msg + "\n" NOR, me, ob);
			return 1;
		}

	message_vision( CYN+msg_dunno[random(sizeof(msg_dunno))]+NOR, me, ob);
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>
指令說明 :
           這個指令在解謎時很重要, 通常必須藉由此一指令才能
         獲得進一步的資訊。
HELP
   );
   return 1;
}
