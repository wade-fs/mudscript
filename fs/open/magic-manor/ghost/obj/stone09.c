inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(NOR+CYN"封靈"NOR+RED"雙石" + NOR,({"fon stone","fon","stone"}));
	set("long","封靈雙石，是封印著左靈晉和右靈兒的封魂石，當他們二人皆死\n"
		  +"亡，封靈雙石就會碎毀!!\n");
	set("unit","顆");
	set("value",100);
	set("no_get",1);
	set("no_sac",1);
	set("no_auc",1);
//	set("check",1);
	set_weight(500000);
        setup();
}

int check(object ob)
{
	ob=this_object();
	call_out("msg1",5,ob);
	return 1;
}

int msg1(object ob)
{
	object room;
	ob=this_object();
	room = environment(ob);

	message_vision(HIC + "\n只見" + NOR + "$N" + HIC + "吸入雙魂後不斷的釋放靈光，並開啟了一條光芒之路!!\n" + NOR,ob);
	room->add("exits/takeroad","/open/magic-manor/ghost/rest10");
	call_out("msg2",60,ob);

	return 1;
}

int msg2(object ob)
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
	  if( bname == "/open/magic-manor/ghost/rest09" )
	  {
	  tell_object(glist[l],HIR + "\n只見到封魂石漸漸的崩碎消失!!\n" + NOR);
	  tell_object(glist[l],HIR + "\n而你"NOR+HIR"漸漸被一道靈光包圍傳送到另一個地方!!\n" + NOR);
	  glist[l]->move("/open/magic-manor/ghost/rest10");
	  }
        }

	for (j=0 ; j < i ; j++)
	{
	  if( !enemy[j] ) continue;
	  {
	    if( enemy[j]->is_character() && living(enemy[j]) && !enemy[j]->query("eight-ghost")&& !enemy[j]->is_corpse() )
	    {
	    tell_object(enemy[j],HIR + "\n只見到封魂石漸漸的崩碎消失!!\n" + NOR);
	    tell_object(enemy[j],HIR + "\n而你"NOR+HIR"漸漸被一道靈光包圍傳送到另一個地方!!\n" + NOR);
	    enemy[j]->move("/open/magic-manor/ghost/rest10");
	    }
	  }
	}
	room->delete("exits/takeroad");
	room->delete("no_reset");
	room->delete("mob-die");
	call_out("msg3",1,ob);
	return 1;
}

int msg3(object ob)
{
	message_vision(HIR + "\n只見$N"NOR+HIR"也漸漸的崩碎消失了!!\n" + NOR,ob);
	destruct(ob);
	return 1;
}
