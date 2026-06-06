// made by ccat
// 二版,改正以往須call 一個隱形怪獸的缺點,使用的變數也大為簡化.

#include <ansi.h>
#include <weapon.h>
#include <combat.h>
inherit BLADE;
inherit SSERVER;
object user;
int sp;
void create()
{
  set_name("屠龍刀",({"dragon blade","blade"}) );
  set_weight(40000);
  if( clonep() ) 
    set_default_object(__FILE__);
  else {
    set("long","一股殺氣撲面而來,刀面閃爍凜凜青光,這就聞名天下的屠龍"+
        "寶刀.\n");
    set("unit", "件");             
    set("value",5000);
    set("no_sell",1);
    set("no_steal",1);
    set("no_save", 1);
    set("no_put",1);
    set("rigidity",200);
    set("sharp",10);
    set("material","crimsonsteel");
  }         
  init_blade(100);
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
  int my_cor,my_exp;
  ::wield();
  if( query("equipped") ) 
  {
    user = this_player();     // 取得使用者
    my_cor = user->query_cor(1);
    my_exp = user->query("combat_exp",1);
    //為表示神兵利器所以調高使用調件
    if( my_exp * my_cor < 10000000 )
    {
      message_vision("$N的膽識與經驗,並不足以號令屠龍刀.\n",user);
      set_name("屠龍刀",({"dragon blade","blade"}) );
      set_heart_beat(0);
    }else{
      message_vision(HIY + "屠龍刀感受到$N的膽識,泛起一層金光.\n" + NOR,user);
      set_name(HIY + "屠龍刀" + NOR,({"dragon blade","blade"}) );
      sp = my_cor;
      set_heart_beat(1);
    }
  } 
}

int do_drop(string str)
{  
  if( str=="all" || str=="blade" || str=="dragon-blade")  
    if( query("equipped") )
    {
      set_name("屠龍刀",({"dragon blade","blade"}) );
      set_heart_beat(0);
    }    
}

int do_give(string str)
{  
  if( str=="all" || str=="blade" || str=="dragon-blade")
    if( query("equipped") )
    { 
      set_name("屠龍刀",({"dragon blade","blade"}) );
      set_heart_beat(0);
    }
}

int do_unwield(string str)
{
  if( str=="all" || str=="blade" || str=="dragon-blade")
    if( query("equipped") )
    {
      message_vision("$N將屠龍刀放回刀鞘.\n",user);
      set_name("屠龍刀",({"dragon blade","blade"}) );
      set_heart_beat(0);
    }   
} 

int do_auc(string str)
{
  if( str=="all" || str=="blade" || str=="dragon-blade")
    if( query("equipped") )
    { 
      set_name("屠龍刀",({"dragon blade","blade"}) );
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
        message_vision("$N大喊" + HIY + "【 寶刀屠龍, 號令天下, 莫敢不從!!! 】\n" + NOR,user);  
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
          message_vision(HIY + "只聽到 __ㄎㄤ__ 一聲，$n"HIY + "的"+ob->query("bname")+HIY"已被屠龍刀斬成兩段!!\n" + NOR,user,enemy[i]);
          ob->unequip();

          bk=new("/open/main/obj/broken");
          bk->set("name", "(斷毀兩段)" + ob->query("bname"));
          bk->set("id", ob->query("id"));
          bk->move(environment(enemy[i]));
          destruct(ob);
          enemy[i]->reset_action();
        }else{
          if( qq > 280 && (1000-od <= 850 && 1000-od > 400) )
          {
            //	        ob->unequip();
            message_vision(HIR + "$N的"NOR+obj->name()+HIR"把$n" + HIR + "的"NOR+ob->query("bname")+HIR"重重的砍出了一個嚴重的缺口!!\n" + NOR,user,enemy[i]);
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
              enemy[i]->add_temp("apply/damage",-10);
              ob->add("weapon_prop/damage",-10);
              ob->wield();
            }else{
              message_vision(RED + "$n"RED + "的"+ob->query("bname")+RED"再也承受不住" + HIY + "屠龍刀" + RED + "的攻擊而完全斷毀了!!\n" + NOR,user,enemy[i]);
              ob->unequip();
              bk=new("/open/main/obj/broken");
              bk->set("name", "(完全斷毀)" + ob->query("bname"));
              bk->set("id", ob->query("id"));
              bk->move(environment(enemy[i]));
              destruct(ob);
              enemy[i]->reset_action();
            }
          }else{
            if( qq > 150 && (1000-od <= 400 && 1000-od > 200) )
            {
              //	          ob->unequip();
              message_vision(HIY + "$N" + HIY + "的"NOR+obj->name()+HIY"把$n"HIY + "的"NOR+ob->query("bname")+HIY"輕輕的砍出了一個小缺口!!\n" + NOR,user,enemy[i]);
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
                enemy[i]->add_temp("apply/damage",-5);

                ob->add("weapon_prop/damage",-5);
                ob->wield();
              }else{
                message_vision(RED + "$n"RED + "的"+ob->query("bname")+RED"再也承受不住" + HIY + "屠龍刀" + RED + "的攻擊而碎裂斷毀了!!\n" + NOR,user,enemy[i]);
                ob->unequip();
                bk=new("/open/main/obj/broken");
                bk->set("name", "(碎裂斷毀)" + ob->query("bname"));
                bk->set("id", ob->query("id"));
                bk->move(environment(enemy[i]));
                destruct(ob);
                enemy[i]->reset_action();
              }
            }else{
              if( qq > 100 && (1000-od <= 200 && 1000-od > 100) )
              {
                message_vision(HIG + "$n" + HIG + "只覺得手中"NOR+ob->query("bname")+HIG"被"NOR+obj->name()+HIG"一震﹐險些脫手飛出!!\n" + NOR,user,enemy[i]);
              }else{
                if( qq > 50 && (1000-od <= 100 && 1000-od > 0) )
                {
                  message_vision(HIW + "$N" + HIW + "的"NOR+obj->name()+HIW"和$n"HIW + "的"NOR+ob->query("bname")+HIW"相擊﹐冒出點點的火星。\n" + NOR,user,enemy[i]);
                }else{
                  if( random(10) > 5 && (1000 == od) )
                  {
                    message_vision(HIM + "$N" + HIM + "的"NOR+obj->name()+HIM"和$n"HIM + "的"NOR+ob->query("bname")+HIM"相擊﹐發出響亮清脆的聲音。\n" + NOR,user,enemy[i]);
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
