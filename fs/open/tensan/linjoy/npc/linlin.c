#include <ansi.h>
string magic();
inherit NPC;
string ask_master();
string ask_badman();
string ask_linjoy();
string ask_tensan();
void create()
{
            set_name("鈴兒",({"lin girl","girl"}));
            set("long","她來自天山，正在到處找人救她的師父，看她著急的模樣真是美若天仙!!\n");
            set("gender","女性");
            set("nickname",HIY"小師妹"NOR);
	    set("title",HIW"天山"+BMAG"靈鷲宮"NOR);
            set("combat_exp",1000000);
            set("attitude","heroism");
            set("age",50);
            set("str", 50);
            set("cor", 50);
            set("cps", 50);
            set("per", 50);
            set("int", 50);
          set("kee",100000);
          set("max_kee",100000);
          set("gin",100000);
          set("max_gin",100000);
          set("sen",100000);
          set("max_sen",100000);
          set("atman",30000);
          set("max_atman",30000);
          set("mana",30000);
          set("max_mana",30000);
          set("force",30000);
          set("max_force",30000);
            set_skill("parry",200);     
            set_skill("force",200);
            set_skill("literate",200);
            set_skill("move",200);
            set_skill("dodge",200);
            set_skill("unarmed",150);      
        set_temp("apply/armor",70);     
        set("force_factor",30);
          set("inquiry",([
         "天山"     :  (: ask_tensan :),
         "靈鷲宮"   :  (: ask_linjoy :),
         "師父"     :  (: ask_master :),
         "奸人暗算" :  (: ask_badman :),
         "李秋水"   :  "我也不曉得為何她們師姐妹會如此恨著對方\n",
    ]));

        setup();
      
}

void init()
{ 
  add_action("do_nod","nod");
  add_action("do_shake","shake");
  remove_call_out("check_kill");
  call_out("check_kill",1,this_player()); 
}

void check_kill(object me)
{  
  object mark=new("/open/tensan/obj/tensan-mark");
  me = this_player();	
  if(me->query_temp("kill_murofu")==1 && me->query_temp("kill_mechoufen")==1 &&
     me->query_temp("kill_kau")==1 && me->query_temp("kill_shion")==1 &&
     me->query_temp("kill_poison")==1 && me->query_temp("kill_wind")==1 &&
     me->query_temp("kill_thunder")==1 && me->query_temp("kill_water")==1 &&
     me->query_temp("kill_fire")==1 &&
     me->query("tensan/accept_help")==1 && !present("tensan mark",me))
  {
     command("say 看來你的實力不差，這是天山通行令，有了這個令牌就可以自由進出天山了。");  
     message_vision("$N交給$n一塊「天山通行令」。\n",this_object(),me);    
     mark->move(me); 	
     me->set_temp("tensan/get_enter",1);
     me->delete_temp("kill_murofu");
     me->delete_temp("kill_mechoufen");
     me->delete_temp("kill_kau");
     me->delete_temp("kill_shion");
     me->delete_temp("kill_poison");
     me->delete_temp("kill_wind");
     me->delete_temp("kill_thunder");
     me->delete_temp("kill_water");
     me->delete_temp("tensan/start_test");
  }else if(present("tensan mark",me))
     command("say 找不到天山嗎？天山位於大陸西北方，你仔細找找應該就可以找到");   
   else if(me->query_temp("tensan/start_test")==1)
     command("say 怎麼這麼快就回來了，你好像還沒通過我的測試耶？");
   else if(me->query_temp("tensan/get_enter")==1 || me->query("tensan/accept_help")==1)
     {
     	command("say 令牌不見了？那就再接受一次我的測試吧！打敗那九個人再來找我");
        me->set_temp("tensan/start_test",1);
     }else{
     command("ssmile");
          }
}
void heart_beat()
{
	object me=this_player();
        object ob=this_object();
        mixed enemy;
	int i,j;
        enemy=all_inventory(environment(ob));
	i=sizeof(enemy);
       
        :: heart_beat();
}

string ask_master()
{
    object me=this_player();
    if(me->query_temp("tensan/ask_linjoy")==1)
    {   
      command("sigh");
      command("say 我師父就是鼎鼎大名的天山童姥，可是她遭奸人暗算現在下落不明");        
      me->set_temp("tensan/ask_master",1);
      me->delete_temp("tensan/ask_linjoy",1);
    }else command("say 我師承何處，要你管喔！");
    return "";
}

string ask_badman()
{
    object me=this_player();
    if(me->query_temp("tensan/ask_master")==1 && me->query_temp("tensan/start_test")!=1)   
    {
      command("say 師父就是被她師妹李秋水暗算才會喪失功\力，大俠你願意幫我找師父嗎？");        
      me->delete_temp("tensan/ask_master");
      me->set_temp("tensan/ask_badman",1);
    }else if(me->query_temp("tensan/start_test")==1)
       command("say 你不是已經答應要幫我救師父了，還不趕快通過我的測試。");
     else command("say 你在說什麼鬼話連篇阿");
    return "";
}

string ask_linjoy()
{
    object me=this_player(); 
    if(me->query_temp("tensan/ask_tensan")==1)   
    {
      command("say 靈鷲宮是我師父一手創建的，師父的武功\可說是天下第一");          
      me->set_temp("tensan/ask_linjoy",1);
      me->delete_temp("tensan/ask_tensan");
    }else command("say 你是從那聽來的，快說？");
    return "";
}

string ask_tensan()
{
    object me=this_player(); 
    command("say 天山這個地方充滿著神奇的傳說，我們靈鷲宮就在天山上");          
    me->set_temp("tensan/ask_tensan",1);
    return "";
}
 
int accept_fight(object ob)
{
	object me=this_player();
        command("say 我還忙著找人救師父，大俠還是另尋他人吧！\n");    
        return 0;
}
int accept_kill(object ob)
{
        command("say 如果把我殺了，靈鷲宮的人不會放過你的!!!\n"); 
        return 1;
}

int do_nod()
{
object me = this_player();
if(me->query_temp("tensan/ask_badman") != 1 && me->query_temp("tensan/start_test")==1) 
   return 0;
 me->set("tensan/accept_help",1);
 me->set_temp("tensan/start_test",1);
 me->delete_temp("tensan/ask_badman");
 command("jump");
 command("say 終於找到人願意幫我了，不過不知道你實力如何？");
 command("say 聽說武林上有九個人擁有神奇的能力，敵人越強他們也就越強");
 command("hmm");
 command("say 這樣好了，如果你能打敗這九人，我就告訴你進入天山的方法");
 return 0;
}

int do_shake()
{
  object me = this_player();
  if(me->query("tensan/ask_badman") != 1)
        return 0;
  command("inn");
  command("say 怎麼辦，再找不到人救師父就慘了");
  return 0;
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
        if(!winner)
	{
	::die();
	return ;
        }
        winner->set("tensan/kill_lin",1);	
        log_file("/tensan/kill_linlin", sprintf("%s(%s) 殺死靈鷲宮鈴兒 on %s\n"
        ,winner->query("name"),winner->query("id"), ctime(time()) ));

	::die();                                                           
}
