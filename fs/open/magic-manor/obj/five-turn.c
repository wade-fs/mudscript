//Edit by Neverend 2001/10/19

inherit ITEM;
#include <ansi.h>
string bname;

object me=this_player();
object ob=this_object();

void create()
{
	seteuid(getuid());
	set_name(HIC + "五轉" + HIW + "聚" + HIY + "靈盤" + NOR,({"five turn","five","turn"}));
	set("long", @LONG
    聚靈山莊的鎮莊寶物，是聚靈莊主「鳳翔天」隨身攜帶的貼身寶
物，相傳如果能獲得五道靈魂注入此中，可以獲得極大的能量，足以
提供攻擊和防護的能力。而且若能配合一陰一陽的聚靈寶物，將是開
啟天靈地界的最重要寶物。

    此寶物必需先將注入在身上的靈魂吸取入靈盤中，方有作用，還
可以將其他人身上所注入的魂魄吸取至靈盤中，但必需本身有一道魂
魄做為牽引，否則將無法作用。

吸取魂魄方式：  suck soul  (對自己)
                suck id    (從別人那吸取)
		set suck   (設定可以提供別人吸取)
靈氣運轉方式：  turn five  (開啟運轉)
                stop five  (關閉運轉)
尋找魂魄方式：  gfind gold (金gold,木wood,水water,火fire,土soil)
組合靈珠方式：  compose ball

LONG);

	set_weight(1000);
	set("value",100000);
	set("unit","塊");
	set("magic-manor-f",1);
	set("no_put",1);
	set("no_drop",1);
	set("no_get",1);
	set("no_sell",1);
	set("no_auc",1);
	set("no_give",1);

	setup();
}

void init()
{
	add_action("do_suck","suck");
	add_action("do_turn","turn");
	add_action("do_stop","stop");
	add_action("do_find","gfind");
	add_action("do_compose","compose");

	if( !ob ) return ;
	if( !me ) return ;

	if( !ob->query("boss") )
	{
	ob->set("boss",me->query("id"));
	}
}

int do_compose(string arg)
{

	if( !arg )
	return 0;

	if( arg == "ball" )
	{
	  if( !present(arg,me) )
	  return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

	  if(!ob->query("five-ball")==1 && (present(arg,me)->query("five-ball")==1) )
	  {
	  message_vision(HIM + "\n$N" + HIM + "將" + HIC + "五轉" + HIW + "聚" + HIY + "靈珠" + HIM + "輕輕的裝在$n" + HIM + "水晶球凹槽上，\n$N" + HIM + "見到$n" + HIM + "發出更強大的靈光快速的運轉!!\n" + NOR,me,ob);
	  ob->set("five-ball",1);
	  me->set_temp("five-ball",3);
	  destruct(present(arg,me));
	  return 1;
	  }else{
	  message_vision(HIR + "$N" + HIR + "已經裝上$n" + HIR + "了!!\n" + NOR,ob,present(arg,me));
	  return 1;
	  }
	}else{
	return notify_fail("你想裝什麼呀？？\n");
	}
}

int do_find(string arg)
{
	int k1,k2,k3,k4,k5;

	if( !arg )
	return 0;

	if( ob != this_object() )
	return 0;

	k1 = me->query("magic-manor/kill-gold");
	k2 = me->query("magic-manor/kill-wood");
	k3 = me->query("magic-manor/kill-water");
	k4 = me->query("magic-manor/kill-fire");
	k5 = me->query("magic-manor/kill-soil");

	if( arg == "gold" )
	{
	  if( !me->query("magic-manor/kill-gold") )
	  {
	  message_vision(YEL + "任$N" + YEL + "怎麼尋找，就是找不到一絲絲的魂魄。\n" + NOR,me);
	  }else{
	    if( me->query("magic-manor/kill-gold") > 100 )
	    {
	      if( !me->query_temp("magic-manor/goldmagic") && !ob->query("suck1") )
	      {
	      message_vision(ob->name()+HIY"泛起一陣靈光，藉$N" + HIY + "之助將遺失在天地間的金色魂魄吸回$n" + HIY + "之中!!\n" + NOR,me,ob);
	      ob->set("suck1",1);
	      }else{
	        if( me->query_temp("magic-manor/goldmagic") )
	        {
		message_vision(YEL + "一道金色魂魄已經存在$N" + YEL + "身體之中了!!\n" + NOR,me);
	        }
		if( ob->query("suck1") )
		{
		message_vision(YEL + "金色靈光已經運轉中!!\n" + NOR,me);
		}
	      }
	    }else{
	    message_vision(YEL + "$N" + YEL + "的靈力似乎不足，無法借助"+ob->name()+NOR+YEL"吸取失落的金色魂魄!!\n" + NOR,me);
	    }
	  }
	}
	if( arg == "wood" )
	{
	  if( !me->query("magic-manor/kill-wood") )
	  {
	  message_vision(GRN + "任$N" + GRN + "怎麼尋找，就是找不到一絲絲的魂魄。\n" + NOR,me);
	  }else{
	    if( me->query("magic-manor/kill-wood") > 100 )
	    {
	      if( !me->query_temp("magic-manor/woodmagic") && !ob->query("suck2") )
	      {
	      message_vision(ob->name()+HIG"泛起一陣靈光，藉$N" + HIG + "之助將遺失在天地間的綠色魂魄吸回$n" + HIG + "之中!!\n" + NOR,me,ob);
      	      ob->set("suck2",1);
	      }else{
	        if( me->query_temp("magic-manor/woodmagic") )
	        {
		message_vision(GRN + "一道綠色魂魄已經存在$N" + GRN + "身體之中了!!\n" + NOR,me);
	        }
		if( ob->query("suck2") )
		{
		message_vision(GRN + "綠色靈光已經運轉中!!\n" + NOR,me);
		}
	      }
	    }else{
	    message_vision(GRN + "$N" + GRN + "的靈力似乎不足，無法借助"+ob->name()+NOR+GRN"吸取失落的綠色魂魄!!\n" + NOR,me);
	    }
	  }
	}
	if( arg == "water" )
	{
	  if( !me->query("magic-manor/kill-water") )
	  {
	  message_vision(CYN + "任$N" + CYN + "怎麼尋找，就是找不到一絲絲的魂魄。\n" + NOR,me);
	  }else{
	    if( me->query("magic-manor/kill-water") > 100 )
	    {
	      if( !me->query_temp("magic-manor/watermagic") && !ob->query("suck3") )
	      {
	      message_vision(ob->name()+HIC"泛起一陣靈光，藉$N" + HIC + "之助將遺失在天地間的水色魂魄吸回$n" + HIC + "之中!!\n" + NOR,me,ob);
	      ob->set("suck3",1);
	      }else{
	        if( me->query_temp("magic-manor/watermagic") )
	        {
		message_vision(CYN + "一道水色魂魄已經存在$N" + CYN + "身體之中了!!\n" + NOR,me);
	        }
		if( ob->query("suck3") )
		{
		message_vision(CYN + "水色靈光已經運轉中!!\n" + NOR,me);
		}
	      }
	    }else{
	    message_vision(CYN + "$N" + CYN + "的靈力似乎不足，無法借助"+ob->name()+NOR+CYN"吸取失落的水色魂魄!!\n" + NOR,me);
	    }
	  }
	}

	if( arg == "fire" )
	{
	  if( !me->query("magic-manor/kill-fire") )
	  {
	  message_vision(RED + "任$N" + RED + "怎麼尋找，就是找不到一絲絲的魂魄。\n" + NOR,me);
	  }else{
	    if( me->query("magic-manor/kill-fire") > 100 )
	    {
	      if( !me->query_temp("magic-manor/firemagic") && !ob->query("suck4") )
	      {
	      message_vision(ob->name()+HIR"泛起一陣靈光，藉$N" + HIR + "之助將遺失在天地間的紅色魂魄吸回$n" + HIR + "之中!!\n" + NOR,me,ob);
	      ob->set("suck4",1);
	      }else{
	        if( me->query_temp("magic-manor/firemagic") )
	        {
		message_vision(RED + "一道紅色魂魄已經存在$N" + RED + "身體之中了!!\n" + NOR,me);
	        }
		if( ob->query("suck4") )
		{
		message_vision(RED + "紅色靈光已經運轉中!!\n" + NOR,me);
		}
	      }
	    }else{
	    message_vision(RED + "$N" + RED + "的靈力似乎不足，無法借助"+ob->name()+NOR+RED"吸取失落的紅色魂魄!!\n" + NOR,me);
	    }
	  }
	}
	if( arg == "soil" )
	{
	  if( !me->query("magic-manor/kill-soil") )
	  {
	  message_vision(BLU + "任$N" + BLU + "怎麼尋找，就是找不到一絲絲的魂魄。\n" + NOR,me);
	  }else{
	    if( me->query("magic-manor/kill-soil") > 100 )
	    {
	      if( !me->query_temp("magic-manor/soilmagic") && !ob->query("suck5") )
	      {
	      message_vision(ob->name()+HIB"泛起一陣靈光，藉$N" + HIB + "之助將遺失在天地間的土色魂魄吸回$n" + HIB + "之中!!\n" + NOR,me,ob);
	      ob->set("suck5",1);
	      }else{
	        if( me->query_temp("magic-manor/soilmagic") )
	        {
		message_vision(BLU + "一道土色魂魄已經存在$N" + BLU + "身體之中了!!\n" + NOR,me);
	        }
		if( ob->query("suck5") )
		{
		message_vision(BLU + "土色靈光已經運轉中!!\n" + NOR,me);
		}
	      }
	    }else{
	    message_vision(BLU + "$N" + BLU + "的靈力似乎不足，無法借助"+ob->name()+NOR+BLU"吸取失落的土色魂魄!!\n" + NOR,me);
	    }
	  }
	}

	return 1;
}

int do_suck(string arg)
{
	object npc;
	int mag1,mag2,mag3,mag4,mag5,su1,su2,su3,su4,su5;

	mag1 = me->query_temp("magic-manor/goldmagic");
	mag2 = me->query_temp("magic-manor/woodmagic");
	mag3 = me->query_temp("magic-manor/watermagic");
	mag4 = me->query_temp("magic-manor/firemagic");
	mag5 = me->query_temp("magic-manor/soilmagic");
	su1 = ob->query("suck1");
	su2 = ob->query("suck2");
	su3 = ob->query("suck3");
	su4 = ob->query("suck4");
	su5 = ob->query("suck5");

	if( !arg )
	return 0;

	if( ob != this_object() )
	return 0;

	if( arg == "soul" )
	{
	  if( su1 == 1 && su2 == 1 && su3 == 1 && su4 == 1 && su5 == 1 )
	  return notify_fail("已無法再吸取任何魂魄。\n");
	  if( !mag1 && !mag2 && !mag3 && !mag4 && !mag5 )
	  return notify_fail("你身上沒有魂魄可吸取。\n");

	    if( mag1 == 1 )
	    {
	      if( ob->query("suck1") != 1 )
	      {
	      message_vision(ob->name()+HIY"泛起一陣靈光，將$N身體中的金色魂魄吸入了"NOR+ob->name()+HIY"。\n" + NOR,me);
	      ob->set("suck1",1);
	      me->delete_temp("magic-manor/goldmagic");
	      }else{
	      message_vision(ob->name()+HIY"已經吸取金色魂魄了。\n" + NOR,me);
	      }
	    }
	    if( mag2 == 1 )
	    {
	      if( ob->query("suck2") != 1 )
	      {
	      message_vision(ob->name()+HIG"泛起一陣靈光，將$N身體中的綠色魂魄吸入了"NOR+ob->name()+HIG"。\n" + NOR,me);
	      ob->set("suck2",1);
		  me->delete_temp("magic-manor/woodmagic");
	      }else{
	      message_vision(ob->name()+HIG"已經吸取綠色魂魄了。\n" + NOR,me);
	      }
	    }
	    if( mag3 == 1 )
	    {
	      if( ob->query("suck3") != 1 )
	      {
	      message_vision(ob->name()+HIC"泛起一陣靈光，將$N身體中的水色魂魄吸入了"NOR+ob->name()+HIC"。\n" + NOR,me);
	      ob->set("suck3",1);
	      me->delete_temp("magic-manor/watermagic");
	      }else{
	      message_vision(ob->name()+HIC"已經吸取水色魂魄了。\n" + NOR,me);
	      }
	    }
	    if( mag4 == 1 )
	    {
	      if( ob->query("suck4") != 1 )
	      {
	      message_vision(ob->name()+HIR"泛起一陣靈光，將$N身體中的紅色魂魄吸入了"NOR+ob->name()+HIR"。\n" + NOR,me);
	      ob->set("suck4",1);
	      me->delete_temp("magic-manor/firemagic");
	      }else{
	      message_vision(ob->name()+HIR"已經吸取紅色魂魄了。\n" + NOR,me);
	      }
	    }
	    if( mag5 == 1 )
	    {
	      if( ob->query("suck5") != 1 )
	      {
	      message_vision(ob->name()+NOR+YEL"泛起一陣靈光，將$N身體中的土色魂魄吸入了"NOR+ob->name()+NOR+YEL"。\n" + NOR,me);
	      ob->set("suck5",1);
	      me->delete_temp("magic-manor/soilmagic");
	      }else{
	      message_vision(ob->name()+NOR+YEL"已經吸取土色魂魄了。\n" + NOR,me);
	    }
	  }
	return 1;
	}

	if( !npc = present(arg,environment(me)) )
//	if( !(npc = find_player(arg)) )
	return notify_fail("此地沒有這號人物哩？！\n");

	if( arg == arg )
	{
	mag1=npc->query_temp("magic-manor/goldmagic");
	mag2=npc->query_temp("magic-manor/woodmagic");
	mag3=npc->query_temp("magic-manor/watermagic");
	mag4=npc->query_temp("magic-manor/firemagic");
	mag5=npc->query_temp("magic-manor/soilmagic");

	  if( su1 == 1 && su2 == 1 && su3 == 1 && su4 == 1 && su5 == 1 )
	  return notify_fail("已無法再吸取任何魂魄。\n");
	  if( !su1 && !su2 && !su3 && !su4 && !su5 )
	  return notify_fail("你沒有吸取任何魂魄作導引，無法吸取別人身上的魂魄。\n");
	  if( !mag1 && !mag2 && !mag3 && !mag4 && !mag5 )
	  return notify_fail("對方身上沒有魂魄可吸取。\n");

	  if( npc->query("env/suck") == "YES" )
	  {
	    if( mag1 == 1 )
	    {
	      if( ob->query("suck1") != 1 )
	      {
	      message_vision(ob->name()+HIY"泛起一陣靈光，將$N身體中的金色魂魄吸入了"NOR+ob->name()+HIY"。\n" + NOR,npc);
	      ob->set("suck1",1);
	      npc->delete_temp("magic-manor/goldmagic");
	      }else{
	      message_vision(ob->name()+HIY"已經吸取金色魂魄了。\n" + NOR,npc);
	      }
	    }
	    if( mag2 == 1 )
	    {
	      if( ob->query("suck2") != 1 )
	      {
	      message_vision(ob->name()+HIG"泛起一陣靈光，將$N身體中的綠色魂魄吸入了"NOR+ob->name()+HIG"。\n" + NOR,npc);
	      ob->set("suck2",1);
	      npc->delete_temp("magic-manor/woodmagic");
	      }else{
	      message_vision(ob->name()+HIG"已經吸取綠色魂魄了。\n" + NOR,npc);
	      }
	    }
	    if( mag3 == 1 )
	    {
	      if( ob->query("suck3") != 1 )
	      {
	      message_vision(ob->name()+HIC"泛起一陣靈光，將$N身體中的水色魂魄吸入了"NOR+ob->name()+HIC"。\n" + NOR,npc);
	      ob->set("suck3",1);
	      npc->delete_temp("magic-manor/watermagic");
	      }else{
	      message_vision(ob->name()+HIC"已經吸取水色魂魄了。\n" + NOR,npc);
	      }
	    }
	    if( mag4 == 1 )
	    {
	      if( ob->query("suck4") != 1 )
	      {
	      message_vision(ob->name()+HIR"泛起一陣靈光，將$N身體中的紅色魂魄吸入了"NOR+ob->name()+HIR"。\n" + NOR,npc);
	      ob->set("suck4",1);
	      npc->delete_temp("magic-manor/firemagic");
	      }else{
	      message_vision(ob->name()+HIR"已經吸取紅色魂魄了。\n" + NOR,npc);
	      }
	    }
	    if( mag5 == 1 )
	    {
	      if( ob->query("suck5") != 1 )
	      {
	      message_vision(ob->name()+NOR+YEL"泛起一陣靈光，將$N身體中的土色魂魄吸入了"NOR+ob->name()+NOR+YEL"。\n" + NOR,npc);
	      ob->set("suck5",1);
	      npc->delete_temp("magic-manor/soilmagic");
	      }else{
	      message_vision(ob->name()+NOR+YEL"已經吸取土色魂魄了。\n" + NOR,npc);
	      }
	    }
	  }else{
	  message_vision(HIW + "$N想從$n身上吸取五靈塔王的魂魄，但是失敗了!!\n" + NOR,me,npc);
	  tell_object(me,"看來對方並不同意你能吸取他身上的魂魄耶!!\n");
	  }
	}

	return 1;
}

int do_turn(string arg)
{
	if( !arg )
	return 0;
	arg=lower_case(arg);
	if( !ob = present(arg,me) )
	return 0;
	if( ob != this_object() )
	return 0;
	if( me->query_temp("magic-manor/turn-five") )
	return notify_fail("你已經在使用"+ob->name(1)+"。\n");

	message_vision(HIW + "$N" + HIW + "輕輕觸動$n" + HIW + "上面的透明水晶球，水晶球似是有所感應。\n\n" + NOR,me,ob);
	message_vision(HIY + "只見$n" + HIY + "內中蘊含的魂魄靈力開始運轉不停，發出柔和的光芒。\n" + NOR,me,ob);
	me->set_temp("magic-manor/turn-five",1);
	ob->set("name",HIW + "(運轉中) "+ob->name(1));
	set_heart_beat(1);
	return 1;
}

int do_stop(string arg)
{
	if( !arg )
	return 0;
	arg=lower_case(arg);
	if( !ob = present(arg,me) )
	return 0;
	if( ob != this_object() )
	return 0;
	if( !me->query_temp("magic-manor/turn-five") )
	return notify_fail("你沒有使用"+ob->name(1)+"。\n");

	ob->set("name",HIC + "五轉" + HIW + "聚" + HIY + "靈盤" + NOR);
	message_vision("$n"NOR+YEL"內中蘊含的魂魄靈力慢慢停止運轉，柔和的光芒漸漸暗淡。\n" + NOR,me,ob);
	me->delete_temp("magic-manor/turn-five");
	set_heart_beat(0);
	return 1;
}

void heart_beat()
{
	object *enemy;
	int i,j,k,su1,su2,su3,su4,su5,cn,cr,cs,kr,it,pr,si,sr,fv;

	cn = me->query_con();
	cr = me->query_cor();
	cs = me->query_cps();
	kr = me->query_kar();
	it = me->query_int();
	pr = me->query_per();
	si = me->query_spi();
	sr = me->query_str();

	su1 = ob->query("suck1");
	su2 = ob->query("suck2");
	su3 = ob->query("suck3");
	su4 = ob->query("suck4");
	su5 = ob->query("suck5");

	if( !me->query_temp("five-ball") )	fv = 0;

	fv = me->query_temp("five-ball");
	
	enemy=me->query_enemy();
	i=sizeof(enemy);

	if( !objectp(me) )
	{
	set_heart_beat(0);
	return;
	}

	if( me->is_fighting() && me->query_temp("magic-manor/turn-five") == 1 )
	{
	  if( !su1 && !su2 && !su3 && !su4 && !su5 )
	  {
	    if( random(100) < (int)((kr+sr+cn+cr+si+cs+it+pr)/15) )
	    {
	    message_vision(HIW + "由" + HIC + "五轉" + HIW + "聚" + HIY + "靈盤" + HIW + "運轉出微弱的五色靈光，輕輕撫平了$N的傷口。\n" + NOR,me,ob);
	    me->receive_curing("kee",random(500));
	    me->receive_heal("kee",random(500));
	    me->receive_curing("gin",random(500));
	    me->receive_heal("gin",random(500));
	    me->receive_curing("sen",random(500));
	    me->receive_heal("sen",random(500));
	    }
	  }else{
//以下的金木水火土五種的心跳，要打死金、木、水、火、土五個靈塔中的
//塔王，並吸取該塔王的魂魄，才能發揮作用，所以每一個心跳寫成獨立型
//態，機單一出現機率也很小，還有另一層條件滿足，每一種的不同，所以
//實際出現機率更小
	    if( su1 == 1 && random(100) < (8+fv) )//金色主定人
	    {
	    message_vision(HIM + "\n夕陽殘照，暮色泛起，餘暉映照於大地，" + HIY + "金極飄魂魄" + HIM + "感受如此無限晚意輕輕帶出

              " + HIW + "----===≡◎ 金封大地式 ◎≡===----
                   "NOR+YEL"  『" + HIY + "金靈蛇動．殘陽墜"NOR+YEL"』\n\n" + NOR,me);
	      for( j=0 ; j < i ; j++ )
	      {
	      k = random(2);
	        if(!enemy[j]) return ;
	        {
		  if( environment(me) == environment(enemy[j]) )
		  {
	            if( k > 0 )
	            {
	            message_vision(HIY + "$N" + HIY + "被此招式隱含宏大的氣勁給完全的封住了行動!!\n" + NOR,enemy[j]);
	            enemy[j]->start_busy(k+1);
	            COMBAT_D->report_status(enemy[j]);
	            }else{
	            message_vision(HIW + "$N" + HIW + "看準了來勢，巧妙的避開了這股氣勁宏大的氣勁。\n" + NOR,enemy[j]);
	            COMBAT_D->report_status(enemy[j]);
		    }
	          }
	        }
	      }
	    }
	    if( su2 == 1 && random(100) < (8+fv) )//綠色主回復
	    {
	    message_vision(HIM + "\n木影叢叢，森然羅列，草木輕揚於風中，" + HIG + "木燃落魂魄" + HIM + "有感於此身形微動隨意發出

              " + HIW + "----===≡◎ 木影森羅式 ◎≡===----
                   "NOR+GRN"  『" + HIG + "木光流鶯．驚天鳴"NOR+GRN"』\n\n" + NOR,me);
	    message_vision(HIG + "魂魄中釋放出巨大的生命氣息，$N" + HIG + "感受在這股氣息中有說不出的受用!!\n" + NOR,me);
	    me->receive_curing("gin",500);
	    me->receive_heal("gin",500);
	    me->receive_curing("kee",1000);
	    me->receive_heal("kee",1000);
	    me->receive_curing("sen",500);
	    me->receive_heal("sen",500);
	      if( random(5) == 2 )
	      {
	      me->clear_condition("cold");
	      me->clear_condition("burn");
	      me->clear_condition("ice");
	      me->clear_condition("blade");
	      }
	    }
	    if( su3 == 1 && random(100) < (8+fv) )//藍色主化內力為己用和降enforce
	    {
	    message_vision(HIM + "\n水氣凝結，龍形漸現，狂嘯奔騰於四海，" + HIC + "水淵流魂魄" + HIM + "感同身受狂意漸起慕然使出

              " + HIW + "----===≡◎ 水襲狂濤式 ◎≡===----
                   "NOR+CYN"  『" + HIC + "水舞狂龍．蒼海嘯"NOR+CYN"』\n\n" + NOR,me);
	      for( j=0 ; j < i ; j++ )
	      {
	      k = random(5);
	        if(!enemy[j]) return ;
	        {
		  if( environment(me) == environment(enemy[j]) )
		  {
	            if( k > 0 )
	            {
	            message_vision(HIC + "$N" + HIC + "被水氣凝住氣血，漸感使不上力，內力也迅速流失!!\n" + NOR,enemy[j]);
	              if( enemy[j]->query("force") > 1000 )
	              {
	              enemy[j]->set("force",(int)(enemy[j]->query("force")-1000));
	              me->add("force",1000);
	              }else{
	              enemy[j]->set("force",0);
	              me->add("force",100);
	              }
	              if( enemy[j]->query("force_factor") > 2 )
	              {
	              enemy[j]->set("force_factor",(int)(enemy[j]->query("force_factor")/2));
	              }else{
	              enemy[j]->set("force_factor",0);
	              }
	            enemy[j]->apply_condition("cold",enemy[j]->query_condition("cold")+5);
	            COMBAT_D->report_status(enemy[j]);
	            }else{
	            message_vision(HIW + "$N" + HIW + "看準了來勢，巧妙的避開了這股氣勁宏大的水氣。\n" + NOR,enemy[j]);
	            COMBAT_D->report_status(enemy[j]);
	            }
		  }
	        }
	      }
	    }
	    if( su4 == 1 && random(100) < (8+fv) )//紅色主攻精氣神
	    {
	    message_vision(HIM + "\n火捲漫天，雲淡風輕，輕煙漫舞於天際，" + HIR + "火飛笙魂魄" + HIM + "別有感觸翩然起舞飄然喚出

              " + HIW + "----===≡◎ 火捲風雲式 ◎≡===----
                   "NOR+RED"  『" + HIR + "火雲鳳舞．翔風飛"NOR+RED"』\n\n" + NOR,me);
	      for( j=0 ; j < i ; j++ )
	      {
	      k = random(7);
	        if(!enemy[j]) return ;
	        {
		  if( environment(me) == environment(enemy[j]) )
		  {
	            if( k > 0 )
	            {
	            message_vision(HIR + "$N" + HIR + "被這漫天的火氣和鋪天蓋\地的焰氣所捲傷，渾身顯的殘破不堪!!\n" + NOR,enemy[j]);
	            enemy[j]->receive_damage("kee",random(500)+1000);
	            enemy[j]->receive_damage("gin",random(250)+500);
	            enemy[j]->receive_damage("sen",random(250)+500);
	            enemy[j]->apply_condition("burn",enemy[j]->query_condition("burn")+5);
	            COMBAT_D->report_status(enemy[j]);
	            }else{
	            message_vision(HIW + "$N" + HIW + "變幻莫測的巧妙步法使了開來，漫天的火氣只和$N" + HIW + "擦身而過。\n" + NOR,enemy[j]);
	            COMBAT_D->report_status(enemy[j]);
		    }
	          }
	        }
	      }
	    }
	    if( su5 == 1 && random(100) < (8+fv) )//藍色主損精氣神之最大值
	    {
	    message_vision(HIM + "\n雷厲風行，驚天動地，橫掃萬物於須臾，" + HIB + "土爆波魂魄" + HIM + "感念深刻聚力一指瞬間擊出

              " + HIW + "----===≡◎ 土爆雷霆式 ◎≡===----
                   "NOR+BLU"  『" + HIB + "土假虎威．地雷震"NOR+BLU"』\n\n" + NOR,me);
	      for( j=0 ; j < i ; j++ )
	      {
	      k = random(9);
	        if(!enemy[j]) return ;
	        {
		  if( environment(me) == environment(enemy[j]) )
		  {
	            if( k > 0 )
	            {
	            message_vision(HIB + "$N" + HIB + "被這萬馬千軍般的飛沙走石刮的渾身是傷，顯得狼狽不堪!!\n" + NOR,enemy[j]);
	            enemy[j]->receive_wound("kee",1000);
	            enemy[j]->receive_wound("gin",500);
	            enemy[j]->receive_wound("sen",500);
	            COMBAT_D->report_status(enemy[j]);
	            }else{
	            message_vision(HIW + "$N" + HIW + "變幻莫測的巧妙步法使了開來，漫天的飛沙走石只和$N" + HIW + "擦身而過。\n" + NOR,enemy[j]);
	            COMBAT_D->report_status(enemy[j]);
		    }
	          }
	        }
	      }
	    }
	  }
	}

	return;
}

int query_autoload()
{
	return 1;
}
