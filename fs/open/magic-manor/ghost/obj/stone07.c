inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(YEL"封魂石"NOR,({"fon stone","fon","stone"}));
	set("long","封印靈魂的神秘石頭，當只有封印靈魂之後才會出現，如果你仔\n"
		  +"細看，會發現封魂石上面似乎少了一點什麼東西，似乎可以插入\n"
		  +"某一種顏色的武器(insert)!!\n");
	set("unit","顆");
	set("value",100);
	set("no_get",1);
	set("no_sac",1);
	set("no_auc",1);
	set_weight(500000);
        setup();
}

void init()
{
	add_action("do_insert","insert");
}

int do_insert(string str)
{
	object ob=this_object(),me=this_player();
	
	if ( !str )
	return 0;

	switch(str)
	{
	case "lin-cloud-fan":

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	if( present(str,me)->query("e-weapon")==1 )
	{
	message_vision(HIC"$N將"NOR"$n"HIC"插入了封魂石中和"NOR"$n"HIC"吻合的位置上!!\n"NOR,me,present(str,me));
	destruct(present(str,me));
	call_out("check",5,ob);
	}else{
	message_vision("$N已經插在正確的位置上囉!!\n",present(str,me));
	}
	break;

	default:

	if( !present(str,me) )	return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	message_vision("$N努力的想把$n插在正確的位置上，卻怎麼試也不成功\!!\n",me,present(str,me));

	break;
	}
	return 1;

}

int check(object ob)
{
	object room = environment(ob);

	message_vision(HIC"\n只見"NOR"$N"HIC"靈光大盛，「轟」的一聲，開啟了通往下一關的道路!!\n"NOR,ob);
	room->add("exits/takeroad","/open/magic-manor/ghost/rest08");
	call_out("msg1",60,ob);

	return 1;
}

int msg1(object ob)
{
        object room,*glist,pl;
        string bname;
        mixed enemy,enemyy;
        int i,j,k,l;
        ob = this_object();
        glist=users();

        enemy = all_inventory( environment(ob) );
        room = environment(ob);

        i = sizeof(enemy);
        k = sizeof(glist);

	for (l=k-1 ; l>=0 ; l--)
	{
	pl=glist[l]->query("id");
	find_player("pl");
	bname = base_name(environment(glist[l]));
	  if( bname == "/open/magic-manor/ghost/rest07" )
	  {
	  tell_object(glist[l],HIR"\n只見到封魂石漸漸的崩碎消失!!\n"NOR);
	  tell_object(glist[l],HIR"\n而你"NOR+HIR"漸漸被一道靈光包圍傳送到另一個地方!!\n"NOR);
	  glist[l]->move("/open/magic-manor/ghost/rest08");
	  }
        }

	for (j=0 ; j < i ; j++)
	{
	  if( !enemy[j] ) continue;
	  {
	    if( enemy[j]->is_character() && living(enemy[j]) && !enemy[j]->query("eight-ghost")&& !enemy[j]->is_corpse() )
	    {
	    tell_object(enemy[j],HIR"\n只見到封魂石漸漸的崩碎消失!!\n"NOR);
	    tell_object(enemy[j],HIR"\n而你"NOR+HIR"漸漸被一道靈光包圍傳送到另一個地方!!\n"NOR);
	    enemy[j]->move("/open/magic-manor/ghost/rest08");
	    }
	  }
	}
	room->delete("exits/takeroad");
	room->delete("no_reset");
	call_out("msg2",1,ob);
	return 1;
}

int msg2(object ob)
{
	message_vision(HIR"\n只見$N"NOR+HIR"也漸漸的崩碎消失了!!\n"NOR,ob);
	destruct(ob);
	return 1;
}
