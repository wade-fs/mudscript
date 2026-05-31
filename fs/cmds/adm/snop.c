
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
        me=this_player();
	seteuid(geteuid(me));
	if( !arg ) {
	  	if( objectp(ob = query_snooping(me)) )
			write("你現在正在監聽" + ob->query("name") + "所收到的訊息。\n");
		return 1;
	} else if( arg=="none" ) {
		if( objectp(ob = query_snooping(me)))
        	//message_vision (HIW + "$N停止監聽$n所收到的訊息。\n"+ NOR,me,ob);
		snoop(me,);
		write("Ok.\n");
		return 1;
	}

	ob = find_player(arg);
	if (!ob) ob = find_player(arg);
	if(!ob || (!ob->visible(ob))) return notify_fail("沒有這個人。\n");
        if (!interactive(ob))
           return notify_fail("不能監聽斷線中的使用者所收到的訊息。\n");
	if(wizhood(ob)=="(admin)"||wizhood(ob)=="(manager)")
		return notify_fail("你不能竊聽大神。\n");
	if( me==ob ) return notify_fail("請用 snoop none 解除監聽。\n");
		
	snoop(me, ob);
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
	write (HIW"你開始監聽"+ob->name()+"所收到的訊息。\n" + NOR);
	//tell_object(ob, HIW + me->name(1) + "開始監聽你所收到的訊息。\n" + NOR);

	return 1;
}

int help()
{
	write(@TEXT
指令格式﹕snoop [<某人>|none]

    監聽其他使用者所收聽的訊息﹐snoop none 則取消監聽。

    注意: snoop 是用來幫助玩家或其他巫師解決問題的，
          不是用來竊取別人隱私權用的，在 snoop  他人之前最好知會對方一下
	  除了抓違法玩家或巫師, 否則侵害他人隱私者，將予以適當處份

TEXT
	);
	return 1;
}
