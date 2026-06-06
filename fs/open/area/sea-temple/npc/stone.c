inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("海佬石",({"hai lo stone","stone"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","一個清澈透明的淡藍色水晶球，大小約一個手掌大。\n");
                set("value",1000);
                set("unit","粒");
        }
        setup();
}

void init()
{
	add_action("do_hold","hold");
}

int do_hold()
{
	object ob,me,mob;
	int force,i,k;		// i 當亂數用 、 k 是建築物的防禦力
	ob=this_object();
	me=this_player();
	if(!ob->query_temp("change"))
	{
		message_vision("$N雙手緊握住$n，$n由手中的縫隙發出淡淡的金光！\n",me,ob);
		ob->set("name",HIY + "(閃耀金光)" + HIC + "海佬石" + NOR);
		ob->set_temp("change",1);
	}
	
	if(environment(me)->query("defence-build") && !me->query_busy() )
	{
		force = me->query("force");

		if( force < 1000 )                        //檢查內力是否夠
		{
			tell_object(me,"你的內力太低，無法轉換。\n");
			return 1;
		}
		else
		{
			i=random(500)+500;		//開始扣內力、加建築防禦力、與delay 3
			me->add("force",-i);
			me->start_busy(3);
			i=random(2)+1;
			environment(me)->add("defence-build",i);
			tell_object(me,"你耗掉一部份的內力輸入至海佬石內。\n");
		}

		if(environment(me)->query("defence-build") > 70 )	//判斷加完後，是否達到標準
		{
			me->add("/area/sea-temple/stone",1);
			tell_object(me,"手中的海佬石開始不安分起來！\n");
			i = me->query("/area/sea-temple/stone");
			if( i < 3 )
			{
				k=3-i;
				tell_object(me,"
海佬突然出現在你面前，並說：太好了，你幫我修復好"+i+"個結界了！還剩下"+k+"個結界！加油啊！
海佬說完後，將你手中的海佬石拿走，並給了你一個新的海佬石。\n");
				new(__DIR__"stone")->move(me);
			}
			else
			{
				tell_object(me,"
海佬再度出現在你面前，一個招手，你眼前的視野突然轉變了...\n");
				me->move("/open/area/sea-temple/s16");
			}
			environment(me)->set("defence-build",10);
			call_out("dest",1,ob);					//達到標準後後，自動消滅
			return 1;
		}
		else
		{
			tell_object(me,"海佬石將你的內力轉移成了結界！\n");	//沒超出範圍，安全的訊息
			if( environment(me)->query("defence-build") > 40 )	//大到一定程度後，野人開始來破壞...
			{
				k = (int)environment(me)->query("defence-build");
				i = k-40 ;					// 0~35的可能性
				if ( random(100) < i )
				{
					i= random(1)+1;
					tell_object(me,HIR + "海佬用千里傳音告訴你：快～某處正被野人破壞，趕快想辦法啊！\n" + NOR);
					mob=new(__DIR__"wild0"+i);
					i = random(15)+1;
					if( i < 10 )
						mob->move("/open/area/sea-temple/s0"+i);
					else
						mob->move("/open/area/sea-temple/s"+i);
				}
			}
		}
	}
	else
		call_out("dest",1,ob);
return 1;
}

void dest(object ob)
{
	tell_object(this_player(),ob->query("name")+"轉入的能量過大！\n");
	tell_object(this_player(),ob->query("name")+"啪的一聲，破裂不見了！\n");
	destruct(ob);
}
