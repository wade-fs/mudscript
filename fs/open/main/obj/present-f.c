//增加心跳攻擊 -- by kalin,用意是目前還沒有一個stabber可以毀器,所以讓這個戰功stabber可以毀器
#include <ansi.h>
#include <weapon.h>
#include <combat.h>
inherit STABBER;
inherit SSERVER;
object user;
int sp;
void create()
{
     set_name(HIW"留香扇"NOR,({"ancient fan","fan"}) );
     set_weight(4000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","相傳是盜帥"HIW"楚留香"NOR"遺留下來的扇子，扇上還有他的真蹟。\n");
            set("unit", "把");             
            set("value",5000);
            set("rigidity",100);
			set("weapon_prop/stabber",10);
			set("weapon_prop/damage",120);
            set("material","crimsonsteel");
           }         
        //init_stabber(80);
        setup();
}

void init()
{
     add_action("do_drop","drop"); 
     add_action("do_auc","auc"); 
     add_action("do_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}

int do_wield(string str)
{ 
     int my_cor;
     ::wield();
     if( query("equipped") ) 
     {
        user = this_player();     // 取得使用者
        my_cor = user->query_cor(1);
          message_vision("$N從懷中把扇子掏出來，扇上有"HIW"楚留香"NOR"三個大字。\n",user);
          sp = my_cor;
          set_heart_beat(1);
     } 
}

int do_drop(string str)
{  
   if( str=="all" || str=="fan" || str=="ancient fan")  
     if( query("equipped") )
     {
        set_heart_beat(0);
     }    
}

int do_give(string str)
{  
   if( str=="all" || str=="fan" || str=="ancient fan")
     if( query("equipped") )
     { 
        set_heart_beat(0);
     }
}

int do_unwield(string str)
{
   if( str=="all" || str=="fan" || str=="ancient fan")
     if( query("equipped") )
     {
        message_vision("$N把扇子合上，小心的收到懷裡。\n",user);
        set_heart_beat(0);
     }   
} 

int do_auc(string str)
{
   if( str=="all" || str=="fan" || str=="ancient fan")
     if( query("equipped") )
     { 
        set_heart_beat(0);
     } 
} 

void heart_beat()
{
	string wo,oo,wn,on;
	object *enemy,ob,obj,bk;
	int i,j,wm,om,ws,os,wd,od,qq;

	obj=this_object();

	if( !objectp(user) )
	{
	set_heart_beat(0);
	return;
	}

	if( user->is_fighting() && query("equipped") )
	{
	enemy=user->query_enemy();
	i=random(sizeof(enemy));
      if( !enemy[i] ) return ;
	  ob=enemy[i]->query_temp("weapon");
	  if( !ob )	return ;
	  if( !ob->query("material") )
	  ob->set("material","iron");
	  if( !ob->query("sharp") )
	  ob->set("sharp",6);
	  if( !ob->query("bname") )
	  {
	  on = ob->query("name");
	  ob->set("bname",on);
	  }
	  if( random(sp+100)> 100 )
	  {
	    if( !ob || random(10) > 8 )
	    {
	    message_vision("$N高唱"HIY"【 天山我獨行～不必相送～ 】\n"NOR,user);  
	      for(j=0;j<=2;j++)
	      COMBAT_D->do_attack(user,enemy[i],user->query_temp("weapon"),2);
	      return;
	    }
	  }else{
	    if( environment(user) == environment(enemy[i]) )
	    {
	    oo = ob->query("material");
	    os = ob->query("sharp");

	    switch(oo)
	    {
	    case "crimsonsteel": om=100;  break;
	    case "blacksteel":   om=90;   break;
	    case "gem":          om=80;   break;
	    case "gold":         om=70;   break;
	    case "silver":       om=60;   break;
	    case "steel":        om=50;   break;
	    case "copper":       om=40;   break;
	    case "iron":         om=30;   break;
	    case "wood":         om=25;   break;
	    case "bone":         om=20;   break;
	    case "leather":      om=15;   break;
	    case "fur":          om=10;   break;
	    case "cloth":        om=5;    break;
	    default:             om=1;    break;
	    }

	    od = om * os;
	    if( od > 1000 ) od=1000;
	    qq = random( 1000-od );

	    if( random(10) > 5 && (1000 - od > 850) )
	    {
        message_vision(HIY" __嗤嗤__ 聲不斷作響，$N的"+ob->query("name")+
          "被"HIW"留香扇"NOR"扇柄來回擊削，刺出了好幾個傷痕。\n"NOR,enemy[i]);
	    ob->unequip();

		bk=new("/open/main/obj/broken");
	    bk->set("name", "(斷毀兩段)" + ob->query("bname"));
	    bk->set("id", ob->query("id"));
	    bk->move(environment(enemy[i]));
	    destruct(ob);
		enemy[i]->reset_action();
	    }else{
	      if( qq > 280 && (1000-od < 850 && 1000-od > 400) )
	      {
	      ob->unequip();
	      message_vision(HIR"$N的"NOR+obj->name()+HIR"把$n"HIR"的"NOR+ob->query("bname")+HIR"重重的砍出了一個嚴重的缺口!!\n"NOR,user,enemy[i]);
	      ob->add("bad",2);
	        if( ob->query("bad") >= 11 )
	        ob->set("name", "(極盡崩碎)" + ob->query("bname"));
	        if( ob->query("bad") == 10 )
	        ob->set("name", "(嚴重損壞)" + ob->query("bname"));
	        if( ob->query("bad") == 9 )
	        ob->set("name", "(殘破不堪)" + ob->query("bname"));
	        if( ob->query("bad") == 8 )
	        ob->set("name", "(不堪使用)" + ob->query("bname"));
	        if( ob->query("bad") == 7 )
	        ob->set("name", "(崩碎多處)" + ob->query("bname"));
	        if( ob->query("bad") == 6 )
	        ob->set("name", "(尚堪使用)" + ob->query("bname"));
	        if( ob->query("bad") == 5 )
	        ob->set("name", "(多處裂痕)" + ob->query("bname"));
	        if( ob->query("bad") == 4 )
	        ob->set("name", "(小有裂痕)" + ob->query("bname"));
	        if( ob->query("bad") == 3 )
	        ob->set("name", "(輕微裂痕)" + ob->query("bname"));
	        if( ob->query("bad") == 2 )
	        ob->set("name", "(輕微缺口)" + ob->query("bname"));
	        if( ob->query("bad") == 1 )
	        ob->set("name", "(輕微受損)" + ob->query("bname"));
	        if( ob->query("weapon_prop/damage") > 10 && ob->query("bad") < 12 )
	        {
	        ob->add("weapon_prop/damage",-10);
	        ob->wield();
	        }else{
	        message_vision(RED"$n"RED"的"+ob->query("bname")+RED"再也承受不住"HIW"留香扇"RED"的攻擊而完全斷毀了!!\n"NOR,user,enemy[i]);

			bk=new("/open/main/obj/broken");
	        bk->set("name", "(完全斷毀)" + ob->query("bname"));
	        bk->set("id", ob->query("id"));
	        bk->move(environment(enemy[i]));
	        destruct(ob);
			enemy[i]->reset_action();
	        }
	      }else{
	        if( qq > 150 && (1000-od < 400 && 1000-od > 200) )
	        {
	        ob->unequip();
	        message_vision(HIY"$N"HIY"的"NOR+obj->name()+HIY"把$n"HIY"的"NOR+ob->query("bname")+HIY"輕輕的砍出了一個小缺口!!\n"NOR,user,enemy[i]);
	        ob->add("bad",1);
	          if( ob->query("bad") >= 11 )
	          ob->set("name", "(極盡崩碎)" + ob->query("bname"));
	          if( ob->query("bad") == 10 )
	          ob->set("name", "(嚴重損壞)" + ob->query("bname"));
	          if( ob->query("bad") == 9 )
	          ob->set("name", "(殘破不堪)" + ob->query("bname"));
	          if( ob->query("bad") == 8 )
	          ob->set("name", "(不堪使用)" + ob->query("bname"));
	          if( ob->query("bad") == 7 )
	          ob->set("name", "(崩碎多處)" + ob->query("bname"));
	          if( ob->query("bad") == 6 )
	          ob->set("name", "(尚堪使用)" + ob->query("bname"));
	          if( ob->query("bad") == 5 )
	          ob->set("name", "(多處裂痕)" + ob->query("bname"));
	          if( ob->query("bad") == 4 )
	          ob->set("name", "(小有裂痕)" + ob->query("bname"));
	          if( ob->query("bad") == 3 )
	          ob->set("name", "(輕微裂痕)" + ob->query("bname"));
	          if( ob->query("bad") == 2 )
	          ob->set("name", "(輕微缺口)" + ob->query("bname"));
	          if( ob->query("bad") == 1 )
	          ob->set("name", "(輕微受損)" + ob->query("bname"));
	          if( ob->query("weapon_prop/damage") > 5 && ob->query("bad") < 12 )
	          {
	          ob->add("weapon_prop/damage",-5);
	          ob->wield();
	          }else{
	          message_vision(RED"$n"RED"的"+ob->query("bname")+RED"再也承受不住"HIM"留香扇"RED"的攻擊而碎裂斷毀了!!\n"NOR,user,enemy[i]);

			  bk=new("/open/main/obj/broken");
	          bk->set("name", "(碎裂斷毀)" + ob->query("bname"));
	          bk->set("id", ob->query("id"));
	          bk->move(environment(enemy[i]));
	          destruct(ob);
			  enemy[i]->reset_action();
	          }
	        }else{
	          if( qq > 75 && (1000-od < 200 && 1000-od > 100) )
	          {
	          message_vision(HIG"$n"HIG"只覺得手中"NOR+ob->query("bname")+HIG"被"NOR+obj->name()+HIG"一震﹐險些脫手飛出!!\n"NOR,user,enemy[i]);
		      }else{
		        if( qq > 25 && (1000-od < 100 && 1000-od > 50) )
		        {
	            message_vision(HIW"$N"HIW"的"NOR+obj->name()+HIW"和$n"HIW"的"NOR+ob->query("bname")+HIW"相擊﹐冒出點點的火星。\n"NOR,user,enemy[i]);
	            }else{
	              if( random(10) > 5 && (1000 == od) )
	              {
	              message_vision(HIM"$N"HIM"的"NOR+obj->name()+HIM"和$n"HIM"的"NOR+ob->query("bname")+HIM"相擊﹐發出響亮清脆的聲音。\n"NOR,user,enemy[i]);
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
  }

	return;
}
