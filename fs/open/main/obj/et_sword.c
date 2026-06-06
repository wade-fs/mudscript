// Et-sword.c by Casey
//由於會因為戰功eq增加的天賦而造成系統溢位，所以強化裝備時的判斷 by blazakira 2011/6/22
//將使用者參數於各函數內重新判斷 避免被玩家get or steal後 參數仍為舊資料 by blazakira 2012/3/29

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIB + "連鞘古劍" + NOR,({"old sword","sword"}) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","\n這是一柄連鞘的古劍，古樸的劍鞘中閃爍著異樣的寒光。\n");
    set("unit", "把");
    set("sharp",10);
    set("value",100000);
    set("no_steal",1);
    set("no_save", 1);
    set("no_sell",1);
    set("no_put",1);
    set("material","crimsonsteel");
    set("rigidity",200);
  }
  init_sword(110);
  setup();
}

void init()
{
  add_action("do_wield","wield");
  add_action("do_give","give");
  add_action("do_unwield","drop");
  add_action("do_unwield","auc");
  add_action("do_unwield","unwield");
}

int do_wield(string str)
{
  object user;
  int my_spi,my_exp,sp;
  user = environment(this_object());

  if( str=="all" || str=="sword" || str=="old sword" && !query_temp("changed") || str=="et-sword" && query_temp("changed")==1 ) {
    ::wield();
    if( query("equipped") )
    {
      my_spi = user->query_spi(1);
      my_exp = user->query("combat_exp");
      // 表示神兵利器 ,所以提高條件...Daniel
      if( my_exp * my_spi < 10000000 )
      {
        message_vision("$N的靈性與經驗，並不足以使用此劍。\n",user);
        set_temp("changed",0);
        set_heart_beat(0);
      } else {
        message_vision(HIW + "鞘中之劍感受到$N" + HIW + "的靈性，隨著一道青光灑然揚出，原來正是聞名天下的" + HIC + "倚天劍" + HIW + "。\n" + NOR,user);
        set_name(HIC + "倚天劍" + NOR,({"et-sword","sword"}) );
        set("long","\n倚天劍傳聞是以寒湖玄鐵打製，其鋒芒足可分金斷玉，在武林與屠龍刀並列。\n");
        sp = my_spi;
        set_temp("changed",1);
        set_heart_beat(1);
      }
    }
  }
}

int do_give(string str) //另有quest的效果 所以give狀態下不恢復原狀 by blazakira
{
  if( str=="all" || str=="sword" || str=="et-sword")
    set_heart_beat(0);
}

int do_unwield(string str)
{
  object user;
  user = environment(this_object());

  if( str=="all" || str=="sword" || str=="et-sword")
    if( query("equipped") && query_temp("changed") )
    {
      message_vision("$N輕輕巧巧的把劍收回腰際。\n",user);
      set("long","\n這是一柄連鞘的古劍，古樸的劍鞘中閃爍著異樣的寒光。\n");
      set_name(HIB + "連鞘古劍" + NOR,({"old sword","sword"}) );
      set_temp("changed",0);
      set_heart_beat(0);
    }
}
/*
int do_drop(string str)
{
  if( str=="all" || str=="sword" || str=="et-sword")
    if( query("equipped") )
    {
      message_vision("$N輕輕巧巧的把劍收回腰際。\n",user);
      set_name(HIB + "連鞘古劍" + NOR,({"old sword","sword"}) );
      set("long","\n這是一柄連鞘的古劍，古樸的劍鞘中閃爍著異樣的寒光。\n");
      set("changed",0);
      set_heart_beat(0);
    }
}

int do_auc(string str)
{
  if( str=="all" || str=="sword" || str=="et-sword")
    if( query("equipped") )
    {
      message_vision("$N輕輕巧巧的把劍收回腰際。\n",user);
      set_name(HIB + "連鞘古劍" + NOR,({"old sword","sword"}) );
      set("long","\n這是一柄連鞘的古劍，古樸的劍鞘中閃爍著異樣的寒光。\n");
      set("changed",0);
      set_heart_beat(0);
    }
}
*/
void heart_beat()
{
  string wo,oo,wn,on;
  object *enemy,ob,obj,bk,user;
  int i,j,wm,om,ws,os,wd,od,qq,sp;
  user = environment(this_object());
  obj=this_object();
  sp=user->query_spi(1);

  if( !objectp(user) )
  {
    set_heart_beat(0);
    return;
  }

  if( user->is_fighting() && query("equipped") )
  {
    enemy=user->query_enemy();
    i=random(sizeof(enemy));
    if(!enemy) return ;
    ob=enemy[i]->query_temp("weapon");
    if( !ob ) return ;
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
      if( !ob || random(10) > 6 )
      {
        message_vision("$N大喊" + HIY + "【 " + HIB + "倚天不出  誰與爭鋒 !! " + HIY + "】\n" + NOR,user);
        for(j=0;j<=2;j++)
          COMBAT_D->do_attack(user,enemy[i],user->query_temp("weapon"),2);
        return;
      }
    } else {
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
          message_vision(HIC + "只聽到 __ㄎㄤ__ 一聲，$n"HIC + "的"+ob->query("bname")+HIC"已被倚天劍斬成兩段!!\n" + NOR,user,enemy[i]);
          ob->unequip();
          bk=new("/open/main/obj/broken");
          bk->set("name", "(斷毀兩段)" + ob->query("bname"));
          bk->set("id", ob->query("id"));
          bk->move(environment(enemy[i]));
          destruct(ob);
          enemy[i]->reset_action();
        } else {
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
            } else {
              message_vision(RED + "$n"RED + "的"+ob->query("bname")+RED"再也承受不住" + HIC + "倚天劍" + RED + "的攻擊而完全斷毀了!!\n" + NOR,user,enemy[i]);
              ob->unequip();
              bk=new("/open/main/obj/broken");
              bk->set("name", "(完全斷毀)" + ob->query("bname"));
              bk->set("id", ob->query("id"));
              bk->move(environment(enemy[i]));
              destruct(ob);
              enemy[i]->reset_action();
            }
          } else {
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
              } else {
                message_vision(RED + "$n"RED + "的"+ob->query("bname")+RED"再也承受不住" + HIC + "倚天劍" + RED + "的攻擊而碎裂斷毀了!!\n" + NOR,user,enemy[i]);
                ob->unequip();
                bk=new("/open/main/obj/broken");
                bk->set("name", "(碎裂斷毀)" + ob->query("bname"));
                bk->set("id", ob->query("id"));
                bk->move(environment(enemy[i]));
                destruct(ob);
                enemy[i]->reset_action();
              }
            } else {
              if( qq > 100 && (1000-od <= 200 && 1000-od > 100) )
              {
                message_vision(HIG + "$n" + HIG + "只覺得手中"NOR+ob->query("bname")+HIG"被"NOR+obj->name()+HIG"一震，險些脫手飛出!!\n" + NOR,user,enemy[i]);
              } else {
                if( qq > 50 && (1000-od <= 100 && 1000-od > 0 ) )
                {
                  message_vision(HIW + "$N" + HIW + "的"NOR+obj->name()+HIW"和$n"HIW + "的"NOR+ob->query("bname")+HIW"相擊，冒出點點的火星。\n" + NOR,user,enemy[i]);
                } else {
                  if( random(10) > 5 && (1000 == od) )
                  {
                    message_vision(HIM + "$N" + HIM + "的"NOR+obj->name()+HIM"和$n"HIM + "的"NOR+ob->query("bname")+HIM"相擊，發出響亮清脆的聲音。\n" + NOR,user,enemy[i]);
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

