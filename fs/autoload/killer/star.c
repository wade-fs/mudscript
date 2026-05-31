//1998.12.15 by wataru
//這次所寫的這一把培養型的武器，說真的我不知道該定位在哪裡
//原本有這一個計畫要作這一類型的武器，但是真正還是跟minimum談論過才去作		
//這一應該是算最基本的陽春型的培養型武器
//目前寫法是等級 乘以400可以加一級，最多一次大約可以加50點
//而且，基本上屬性想要有風土水火光暗
//但是，其實這牽涉到的問題比較大，並不好做
//最好是分成數把武器，如刀，劍，筆，空手武器。。。。等
//但是，這一把武器的定位在哪？我也不清楚。
//如果每個門派都有一把這種超強武器的話，是否會變成FS的特色之一？
//還是說，反而特色盡失？因為這一種武器好玩但沒特色。
//講難聽一點，我如果在武器上搞各更有趣的東西
//如勇者鬥惡龍系列的魔法，都是跟等級有關會出現
//所以說把魔法寫在武器上，讓武器到一定等級，就有哪些魔法可以用
//如光系的魔法就是回復系，輔助系，等級不同可以用的魔法也不同
//暗系的魔法就是精神傷害系的魔法
//如果說，蔫火系與水系做下去，就還可以有火焰魔法
//但是這一把武器的定位就出現問題了，那就是給誰用（這不一定是匕首）
//給魔法系的門派嗎？她們自己就有了，其實根本不需要
//給非魔法系的門派嗎？特色不合，對用魔法的門派不公平
#include <ansi.h>
#include <weapon.h>
#include <armor.h>
#include "/open/open.h"
inherit UNARMED;
object user;
void create()
{
   seteuid(getuid());
   set_name("幻星破",({ "star unarmed","star"}) );
   set_weight(2000);
   if( clonep() )
         set_default_object(__FILE__);
   else 
   {
     set("long",@LONG
     這是傳說中，會隨著助人的培養方式不同，而成長的武器，注意光暗的力量相剋
     下列是你可以對他下的命令，詳細內容請打help star
     鍛鍊(discipline)        格式 discipline             ：以自身力量使光系力量成長
     吸收(absorb)     	  格式 absorb <target>    ：吸收對方使暗黑系力量成長
     命名(rename)   	  格式 rename <name>   ：為換星破改名
     資料(star_data)         格式 star_data              ：察看幻星破目前的水準
LONG);
     set("unit","對");
     set("value",100);
     set("material", "steel");
     set("ski_type","unarmed");
     set("no_sell",1);
//   set("no_drop",1);
     set("no_auc",1);
   }
   init_unarmed(1);
   set("wield_msg", HIG"$N裝備上$n，萬點星光在$n閃耀著。\n"NOR);
   set("unwield_msg", HIG"$N放下$n，$n也漸漸失去光芒。\n"NOR);
   //更新原有的攻擊力
       if (this_player()->query("dag/sun/lv") > 2)
   	  this_object()->set("weapon_prop/damage",this_player()->query("dag/sun/at"));
       else
    	  this_object()->set("weapon_prop/damage",this_player()->query("dag/dark/at"));
   setup();
}

void init()
{
   if( this_player()==environment() )
   {
    if(this_player()->query("id") == "reko"  || this_player()->query("id") =="wataru"
       || this_player()->query("id") == "meme")
    {
       add_action("feed_dag","discipline");
       add_action("target_absorb","absorb");
       add_action("rename_dag","rename");
       add_action("verify_pet","star_data");
       add_action("help_dream","help");
    }
   }
   user=this_player();
}

int feed_dag(string arg)
{
   object obj,me=this_player();
   int limit_force,daglv;
   int expm;

   if(arg)  return notify_fail("指令格式: discipline \n");
//為了避免強者超好練，所以每次用5%來練
//且限制下限,max_force 1000的5%是50
   limit_force=me->query("max_force")/100;
   limit_force= limit_force *5;
   if (limit_force < 50)
	return notify_fail("你的內力不夠精純，不足以培養光系力量。\n");
   if(me->query("force") < limit_force)
	return notify_fail("少年的。。。。內力不夠啦！\n");
//檢查上一次練，這一次練之間的時間差之間必須相隔1 min
//如果之前都沒練，那qktime會是零，自然可以練第一次
   if ((me->query("mud_age") - this_object()->query("qktime")) < 60)
	return notify_fail("少年的。。。。給點時間消化，之前送入的內力！\n");
   this_object()->set("qktime",me->query("mud_age"));

   message_vision(HIG"$N將內力源源不斷的送入"+this_object()->name()+"之中。\n"NOR,me);
   me->add("force",-limit_force);

//這裡是檢查是否第一次鍛鍊這一把武器
//沒有的話，就為玩家座第一次的資料設定
   if (!me->query("dag/sun/lv"))
   { 
      me->set("dag/sun/power",1); 
      me->set("dag/sun/lv",1);
      me->set("dag/sun/at",1);
   }    
//內力越高，一次可練得量就較多
   expm=random(limit_force)/5;
   me->add("dag/sun/power",expm);
//讀出目前的光系力量
//目前暫時不考慮，光與暗之間的力量消長
   expm=me->query("dag/sun/power");
   daglv=me->query("dag/sun/lv");
   if (expm >= (daglv * 400))  //升級
   {
    daglv += 1;
     if (daglv > 200)
       daglv=200;
     if ( me->query("dag/dark/lv") > 1)
     {//因為光暗相剋，所以武器等級下降且調整攻擊力
	me->add("dag/dark/lv",-1);
	me->set("dag/dark/at",(me->query("dag/dark/lv")/2)+1);
     }
     message_vision(HIC"$N手中的"+this_object()->name()+"發出神聖的光輝。\n"+
		"看來威力更上一層樓了\n"NOR,user);
     me->set("dag/sun/lv",daglv);
     me->set("dag/sun/at",(daglv/2)+1);
     me->set("dag/sun/power",1);
     this_object()->delete("weapon_prop/damage");
     this_object()->set("weapon_prop/damage",this_player()->query("dag/sun/at"));
// 因為score本身所抓的是me->query_temp("apply/damage");
// 所以攻擊力調整要連這裡也要調整

// me->add("max_force",-5"); 升級所需的內力

     expm=0;
   }
   this_object()->set("sunlv",me->query("dag/sun/lv"));
   this_object()->set("sun",me->query("dag/sun/power"));
   return 1;
}

int target_absorb(string str)
{
	object ob,me=this_player();
	int i, exp1 , exp2,upexp,expm;
	int daglv;

//	if(!this_player()->query("quests/lotch") )
//		return notify_fail("你還不會使用煉妖壺 !\n");
	if(!str)
		return notify_fail("你要吸收什麼 ?\n");
	if( (int)this_player()->query("bellicosity")< 5)
		return notify_fail("你沒有足夠殺氣來吸收對手\n");
	str=lower_case(str);
	if(!objectp(ob=present(str,environment(this_player()))))
		return notify_fail("沒這種生物 !\n");
	if(userp(ob))
		return notify_fail("哇哩勒 , 連 player 也要抓 ?\n");
        if(!ob->is_character())
        	return notify_fail("沒有生命力的東西，無法增強暗系力量!!\n");
	
	if( (int) ob->query("max_kee")/5 < (int) ob->query("kee"))
	{
		this_player()->start_busy(1);
		return notify_fail("敵人仍然生命力旺盛 , 你無機可趁 !\n");
	}
	message_vision(HIM"$N揚起$n,殺氣凝聚於$n，幻出紫氣 \n"NOR,this_player(),this_object());
	exp1= (int)ob->query("combat_exp");
	//太弱小，不可以吸收
	if ( exp1 < 50000)
        {
		message_vision(HIR"$N太弱小，不足以增強暗系力量\n"NOR,ob);
		return 1;
	}
	exp2=(int)this_player()->query("combat_exp");
	if( random(exp2) > random(exp1)/2 )
	{
	   message_vision(HIM"結果成功\的把$N吸收\n"NOR,ob);
	//這裡是檢查是否第一次鍛鍊這一把武器
	//沒有的話，就為玩家座第一次的資料設定
	   if (!me->query("dag/dark/lv"))
	   { 
	      me->set("dag/dark/power",1); 
	      me->set("dag/dark/lv",1);
	      me->set("dag/dark/at",1);
	   }    
	//避免強者老是欺負弱自己太多的，基本上最多可獲得約300點
	   if ( exp2 > exp1*2)
		upexp=1;
	   else
		upexp=2;
	//對手越強，一次可練得量就較多
	   expm=exp1 /20000;
	   expm=random(expm)* upexp;
	   me->add("dag/dark/power",expm);
	//讀出目前的暗系力量
	   expm=me->query("dag/dark/power");
	   daglv=me->query("dag/dark/lv");
	   if (expm >= (daglv * 400))  //升級
	   {
	    	daglv += 1;
	     	if (daglv > 200)
		       daglv=200;
		me->set("dag/dark/lv",daglv);
		if ( me->query("dag/sun/lv") > 1)
		{//因為光暗相剋，所以武器等級下降且調整攻擊力
			me->add("dag/sun/lv",-1);
			me->set("dag/sun/at",(me->query("dag/sun/lv")/2)+1);
                }
		me->set("dag/dark/at",(daglv/2) +1);
		me->set("dag/dark/power",1);
                message_vision(HIM"$N手中的"+this_object()->name()+"發出紫色的光輝。\n"+
		"看來威力更上一層樓了\n"NOR,user);
	        this_object()->delete("weapon_prop/damage");
                this_object()->set("weapon_prop/damage",this_player()->query("dag/dark/at"));
		// me->add("max_force",-5");
    	        expm=0;
	   }
	   this_object()->set("darklv",me->query("dag/dark/lv"));
	   this_object()->set("dark",me->query("dag/dark/power")); 
	   destruct(ob);
	   this_player()->add("bellicosity",-5);
	   return 1;
	}
	message_vision(HIB"結果$N在千鈞一髮之際 , 躲了開去\n"NOR,ob);
	this_player()->add("bellicosity",-1);
	return 1;      
}

int rename_dag(string arg)
{
   if(!arg) return notify_fail("你想為幻星破取什麼名字呢?\n");
   arg = trans_color(arg);
   this_object()->set_name(arg + NOR,({ "star unarmed","star"}) );
   write("你替幻星破取了個名字叫"+this_object()->name()+"。\n");
   return 1;
}

int verify_pet(string str)
{
  int slv,dlv,sun,dark,sunAT,darkAT;
  object obj=this_object();

  slv   =  (int)obj->query("sunlv");
  dlv   =  (int)obj->query("darklv");
  sun   =  (int)obj->query("sun");
  dark  =  (int)obj->query("dark");
  sunAT =  (int)this_player()->query("dag/sun/at");
  darkAT=  (int)this_player()->query("dag/dark/at");
  write(obj->name()+"      目前光系等級   :  "+slv+"\n\n");
  write(obj->name()+"      目前光系能量   :  "+sun+"\n\n");
  write(obj->name()+"      目前光系攻擊力 :  "+sunAT+"\n\n");
  write(obj->name()+"      目前暗系等級   :  "+dlv+"\n\n");
  write(obj->name()+"      目前暗系能量   :  "+dark+"\n\n");
  write(obj->name()+"      目前暗系攻擊力 :  "+darkAT+"\n\n");
  return 1;
}

mixed hit_ob( object me,object victim)
{
  object *enemy,who;
  int doglv,i,sunlv,darklv;
  int sp=1; //假設一開始就是光之力量

  doglv=user->query_skill("dodge",1);
  sunlv=user->query("dag/sun/lv");
  darklv=user->query("dag/dark/lv");

  if (sunlv < darklv)
	sp=2;	//代表暗黑力量

  if( user->is_fighting() && query("equipped") )
  {
    if( random(100) > 30 )  //使驅動機率降到 30%
    {
    	enemy=user->query_enemy();
	i=random(sizeof(enemy));
     	switch(sp)
	{//為了擴展性，例如還可以加入火之屬性與水之屬性
	 case 1:
	 {//目前是試作版，只有一些訊息與補氣
	  //基本上還可以根據匕首等級的不同，有不一樣的特攻
	  //甚至連特攻的屬性都不一樣
	  //或許連武器上都可以做自己決定要用的特攻魔法
      		message_vision(HBCYN"化出聖光氣,籠罩住$N!!"NOR,enemy[i]);
		message_vision(HBCYN"聖光氣由$N身上，回到$n的體內!!"NOR,enemy[i],user);
		enemy[i]->receive_damage("kee",random(sunlv*2),user);
	        COMBAT_D->report_status(enemy[i], 0);
		user->add("kee",random(sunlv/2));
		if (user->query("kee") > user->query("max_kee"))
			user->set("kee",user->query("max_kee"));
		break;
         }
	 case 2:
	 {
      		message_vision(HBMAG"化出數道鬼影，衝向$N!!！！"NOR,enemy[i]);
		message_vision(HBMAG"$N在精神層面上受到很大的打擊!!"NOR,enemy[i]);
		enemy[i]->add("sen",-random(darklv));
		enemy[i]->add("gin",-random(darklv));
	        COMBAT_D->report_status(enemy[i], 0);
		break;
	 }
	} // switch block
   }
   else
      message_vision(HIW"$N巧妙的躲開攻擊\n"NOR,enemy[i]);
  }
}

int help_dream(string str)
{
   if(str != "star")  
         	return notify_fail("打錯了");
write(@HELP
幻星破，可以隨著你養育他的方法而成長，具有光明與黑暗兩系的力量。
兩種力量並不相容，所以當其中一方的力量增強，另一方的力量必然下降。
所以，想讓幻星破同時具有兩種屬性是不可能的。
幻星破在光系的力量是以回復自身為主，暗系的力量是以傷害對手為主。
因此，光系的力量必須以自身的內力去培養，
      暗系的力量必須以吸收對方的力量來成長。（必須很虛弱）

HELP
	);
	return 1;
}

int query_autoload()
{
 return 1;
}

