// 段家 門人 made by onion
#include "/open/open.h"
inherit NPC;
string do_duan();
string do_thief();
string do_linpo();
int do_gone();
object ob=this_object();
void create()
{
        set_name("京城大盜",({"great thief","thief"}));
        set("long","雖然他是一名被通緝的大盜, 但眉目間卻隱隱有一股不凡的氣質。\n"+
            "似乎向來與流水行雲同渡, 跟落霞孤騖齊飛。\n");
        set("gender","男性");
        set("class","scholar");
        set("combat_exp", 100000);
        set("attitude","heroism");
        set("age",44);
        set("inquiry", ([
        "duan" : (: do_duan :),
        "段家" : (: do_duan :),
        "chao" : (: do_duan :),
        "thief" : (: do_thief :),
        "凌波微步秘笈" : (: do_linpo :),
        "小師弟" : "你以為我會跟你說嗎!哼，想都別想!!",
        ]));
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: this_object(),"do_gone" :),
        }));
        set("force",1000);
        set("max_force",1000);
        set("force_factor", 20);
        set_skill("force",40);
        set_skill("dodge",70);
        set_skill("unarmed",30);
        set_skill("sunforce",40);
        set_skill("linpo-steps",60);
        set_skill("six-fingers",71);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("unarmed","six-fingers");
        set_temp("apply/dodge",50);
        set_temp("apply/damage",50);
        set_temp("apply/armor",100);
        setup();
        carry_object(CAPITAL_OBJ"cloth1")->wear();
        carry_object(CAPITAL_OBJ"pen0")->wield();
        carry_object(CAPITAL_OBJ"pen0")->wield();
        add_money("silver",10);
}

void init()
{
        add_action("do_forgive","forgive");
        add_action("do_want","want");
}
string do_duan()
{
	object me=this_player();
	if( !me->query_temp("thief") )
	{
	return("別吵！滾到一邊涼快去！\n");
	}else{
        set_name("趙琴風",({"chao"}));
        return("原來你已經知道我是段家的人了。\n");
	}
}
string do_thief()
{
        object me=this_player();
        if( !this_object()->queyr_temp("lost") && me->query_temp("thief") == 8 )
        {
        me->set_temp("thief",9);
        remove_call_out("do_flee");
        call_out("do_flee",3);
        set_name("趙琴風",({"chao"}));
        return("不錯, 我便是趙琴風, 京城的案子都是我做的, 但我所偷的是那些文臣武官在民間搜括、"+
        "強徵得來的錢財古玩, 賬濟的是給搜括一空的貧眾, 雖違理, 卻合情。這等事, "+
        "別人不敢做, 我偏偏要做, 只要是合於我心, 又有什麼不可以。\n");
        }
        else
        return("這不關你的事。\n");
}
string do_linpo()
{
        object me=this_player();

        if(this_object()->query("name")!="趙琴風")
          return 0;
        if(me->query("family/family_name")!="段家")
          return "我不懂你在說什麼。";
        if(me->query("marks/ask_linpo")!=1)
          return "你別亂說，打死我也不會作出對師門不敬的事!!\n";
        me->set("marks/ask_linpo",2);
        command("hmm");
        return "真沒想到你竟然知道這件事，不過你找我也沒用，因為我已經把秘笈送給我的小師弟了。";
}
void do_flee()
{
        object me=this_player();
        tell_room(environment(ob),query("name")+"身形一退, 似乎想要逃走, 但你眼明手快的把他擋了下來。\n");
        message_vision("$N和$n打了起來。\n",me,ob);
        ob->fight_ob(me);
}

int do_gone()
{
        object *me;
        me=ob->query_enemy();
        if( me[random(sizeof(me))]->query_temp("thief") != 9 )
        {
          command("say 連話都不說明白是吧..告辭了。");
          tell_room(environment(ob),query("name")+"身形一動, 人影一晃, 便不知所蹤了。\n");
          destruct(ob);
        }
        return 1;
}

void unconcious()
{
        object winner = query_temp("last_damage_from");
        if( !query_temp("lost") && !winner->query("quests/catch_thief") )
        {
          message_vision("$N從急急忙忙的從懷裡掏出一顆小還丹運功\服化。\n",ob);
          command("say 既然我技不如人  那就任憑你處置吧");
          tell_object(winner,"你要原諒(forgive)他嗎?\n");
          ob->set_temp("lost",getuid(winner));
          winner->remove_all_enemy();
	  winner->remove_all_killer();
          ob->set("kee",100);
	  ob->set("eff_kee",100);
        }
        else
        {
          ob->delete_temp("undead");
          :: unconcious();
        }
}

int do_forgive(string str)
{
        object me=this_player();
        if(ob->query_temp("lost") == getuid(me) && !me->query("quests/catch_thief") )
        {
          command("say 好, 承蒙"+RANK_D->query_respect(me)+"看的起我, 給我這"+
          "一次機會, 我這就洗手不幹了。");
          if( !ob->query_temp("get_reward") )
          {
            message_vision("$N從懷中掏出兩件東西。\n",ob);
            command("say 這兩件寶物是我多年前無意中得來的, 一是一顆九轉金丹(pi"+
            "ll), 二是一把神兵利器(weapon), 為了感謝你, 就送你其中一件吧, 你想"+
            "要(want)什麼呢?");
            if( !me->query("quests/catch_thief") )
            {
            write("\n\n[1;36***完成京城大盜之謎***\n得到實戰經驗 200。\n");
            me->set("quests/catch_thief",1);
            me->set_temp("can_get_reward",1);
            me->add("combat_exp",200);
            me->delete_temp("thief");
            }
          }
          else
          {
            command("say 這就告辭了。");
            destruct(ob);
          }
          return 1;
        }
        return 0;
}
int do_want(string str)
{
        object me=this_player();
        object reward;
        int kind;
        if( me->query("quests/catch_thief") || !ob->query_temp("get_reward") || me->query_temp("can_get_reward") )
        {
          if( str == "pill" || str == "weapon")
          {
            if( str == "weapon" )
            {
              if( me->query("class") == "blademan" || me->query("class") == "swordsman" )
              {
              if( me->query("class") == "blademan" )
                kind=random(2)+3;
              if( me->query("class") == "swordsman" )
                kind=random(2)+1;
              }
              else
                kind=random(4)+1;
	      if ( me->query("combat_exp") < 150000 || me->query("quests/catch_thief") ) 
	      {
		 if ( random(2) == 0 )
	            kind = 1;
  		 else 
	            kind = 4;
	      }
              switch(kind)
              {
              case 1 :
              reward=new(CAPITAL_OBJ"4-1");                     break;
              case 2 :
              reward=new(CAPITAL_OBJ"4-4");                     break;
              case 3 :
              reward=new(CAPITAL_OBJ"4-3");                     break;
              case 4 :
              reward=new(CAPITAL_OBJ"4-2");                     break;
              }
            }
            if( str == "pill" )
              reward=new(CAPITAL_OBJ"gold_pill");
            message_vision("$N將手上的"+reward->query("name")+"交給$n。\n",ob,me);
            if( me->query_max_encumbrance() - me->query_encumbrance() > reward->query_weight() )
              reward->move(me);
            else
            {
              message_vision("$N身上太重了, 故$n將"+reward->query("name")+"置於地上。\n",me,ob);
              reward->move(environment(me));
            }
            if( str == "weapon" )
              command("say 此把武器業已封塵多年, 必須要以自身精氣神先開光(blood)後才有威力。");
            ob->set_temp("get_reward",1);
            me->delete_temp("can_get_reward");
            command("say "+RANK_D->query_respect(me)+"告辭了, 就此拜別。");
            tell_room(environment(ob),ob->query("name")+"轉動石桌後, 上頭露出"+
            "一個大洞, 他便從此洞爬了出去, 之後這個大洞又緩緩的關閉。\n");
            destruct(ob);
          }
          else
            command("say 什麼?");
          return 1;
        }
        else
          return 0;
}
