#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "天靈一隔牆");
	set ("long", @LONG


       ◥▇▆▄▃▁◣                                    ◢▁▃▄▆▇◤
      ◥████$HIR$▆$NOR$██                                  ██$HIR$▆$NOR$████◤
      ◢█ ███   ◤                                  ◥   ███ █◣
    ◢██▅ ██◤                                        ◥██ ▅██◣
    ◢███▅ ◤                                            ◥ ▅███◣
    ◢████◣                                              ◢████◣
   ███████                                            ███████
   ██$HIY$◢█◣$NOR$██                                            ██$HIC$◢█◣$NOR$██
     █  $HIY$██$NOR$█                                                █$HIC$██  $NOR$█
     █$HIY$◥█◤$NOR$█                                                █$HIC$◥█◤$NOR$█
    ██████                                              ██████
  ████████                                          ████████
▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
來到這裏你的前面已經沒有路了，只見到一面光滑的牆，牆的兩旁還
刻有兩頭對望的奇獸圖案，獸形圖案上還各有一個缺口，似乎可以鑲
入特別的東西。

LONG);

	set("no_auc", 1);
	set("no_transmit", 1);
	set("no_chome", 1);

	set("exits", ([
	"backroad"	:	"/open/magic-manor/ghost/road10",
	"outroad"	:	"/open/magic-manor/ghost/fon02",
	]));

	set("light_up", 1);

	setup();
}

void init()
{
	add_action ("do_insert","insert");
}

int do_insert (string str)
{
	object me,ob;

	me = this_player();
	ob = this_object();
	
	if( !str )
	return 0;

	switch(str)
	{
	case "sun heart":

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("sun")==1 && (present(str,me)->query("go-sky")==1) )
	{
	message_vision(HIG"$N將"NOR"$n"HIG"鑲入了牆上$n"HIG"的位置上!!\n"NOR,me,present(str,me));
	ob->set("sun",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "lunar heart":

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if(!ob->query("lunar")==1 && (present(str,me)->query("go-sky")==1) )
	{
	message_vision(HIG"$N將"NOR"$n"HIG"鑲入了牆上$n"HIG"的位置上!!\n"NOR,me,present(str,me));
	ob->set("lunar",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	case "five turn":

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if( !ob->query("sun") == 1 || !ob->query("lunar") == 1 ) return notify_fail("你找不出任何地方可以放置這東西!!\n");

	if( !ob->query("five") == 1 && (present(str,me)->query("magic-manor-f") == 1) )
	{
	message_vision(HIG"$N將"NOR"$n"HIG"鑲入了牆上$n"HIG"的位置上!!\n"NOR,me,present(str,me));
	ob->set("five",1);
	destruct(present(str,me));
	call_out("check",1,ob);
	}else{
	message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
	}
	break;

	default:

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");
	message_vision("$N似乎想放什麼東西，但卻找不到正確的位置放!!\n",me);
	break;
	}
	return 1;

}

int check(object me)
{
	object room;
	me=this_player();
	room=environment(me);

	room->add("check",1);

	if(room->query("check") == 2 )
	{
	message_vision(HIY"\n\n忽然間，左右兩邊的獸形圖案各發出了一道強光!!\n"NOR,me);
	message_vision(HIY"\n強光交匯在兩獸的中央，形成了一個若有似無的五行圖缺口!!\n\n"NOR,me);
	}

	if(room->query("check") == 3 )
	{
	message_vision(HIY"\n只見鑲入牆上的三樣靈器發出強烈的光芒，交匯融合著，不斷的催生一股強大的力量!!\n\n"NOR,me);
	call_out("msg1",5,me);
	}
	return 1;
}

int msg1(object me)
{
	message_vision(HIM"\n就在一陣光芒中，光滑的牆面開始一分為二，緩緩的向兩旁推開!!\n\n"NOR,me);
	tell_object(users(),HIC"\n大地開始搖動不止，靈力正從天靈地界之中瘋狂的宣洩出來!!\n\n"NOR);
	call_out("msg2",10,me);
	return 1;
}

int msg2(object me)
{
	object room = environment(me);
	room->start();
	tell_object(users(),HIC"\n天搖地動和宣洩的靈氣漸漸的止息，通往天靈地界的唯一入口卻緩緩的開啟了!!\n\n"NOR);
	room->add("exits/takeroad","/open/magic-manor/ghost/sky01");
	call_out("close",600,room);
	return 1;
}

int close(object room)
{
	room = this_object();

	tell_object(users(),HIB"\n大地又開始一陣輕微的搖晃，卻是天靈地界的入口緩緩的自行關閉了!!\n\n"NOR);
	room->delete("exits/takeroad");
	return 1;
}
