 
#include <ansi.h>
 
inherit NPC;
 
int test_limit();
 
int party_with(string str)
{
   object me,obj;
   string str1;
   me=this_player();
   if(!str || sscanf(str,"with %s",str1) != 1)
       return notify_fail("格式﹕ party with <npc> \n");
   if( this_object() != (obj = present(str1,environment(me))))
       return notify_fail("你想和誰組隊？\n");
   if(!str1=obj->query("be_party_msg"))
       str1 = "這位"+obj->name()+"大俠是否肯與在下同行?";
   message_vision(
       CYN + "$N說道﹕"+str1+"\n" + NOR,me,obj);
// 底下為有 party 條件限制的
   if(obj->query("lim")==1)
        if(test_limit()==0)
          {
           if(!str1=obj->query("lim_msg"))
               str1= "我不願與你為伍。";
           command("say "+str1+"\n");
           return 1;
          }
 
   if(obj->query_temp("id")) {
       command("shake");
       command("say 很抱歉，我已經追隨別人囉。");
       return 1;
       }
 
   if(me->query_temp("party_number") >= 5) {
       command("hmm");
       command("say 你的隊伍陣容已經很強大了，不需要我加入。");
       return 1;
       }
 
   if(!str1 = obj->query("parry_succeed_msg"))
       str1 = "好吧! 就讓我們一起同行吧!";
   command("say "+str1);
   command("follow "+me->query("id"));
   me->set_temp("party_number", me->query_temp("party_number")+1);
   obj->set("describe","他目前是"+me->name()+"的組員。\n");
   obj->set_temp("id",me->query("id"));
   return 1;
}
int test_limit()
{
        return 0;
}
int unparty(string str)
{
   object me,obj;
   me=this_player();
   if( this_object() != (obj = present(str,environment(me))))
       return notify_fail("你想跟誰脫離隊伍關係?\n");
   if(me->query("id")!=obj->query_temp("id"))
       return notify_fail("他並不屬於你的隊伍。\n");
   message_vision(
     CYN + "$N說道﹕"+obj->name()+" ! 我們之間的隊伍關係到此為止。\n" + NOR,me,obj);
   command("say 你.......");
   command("say 哼!!...");
   if(obj->query("will_angry")==1)
   {
      command("say 你這個無情無義的人....納命來 !");
      obj->kill_ob(me);
   }
   me->set_temp("party_number", me->query_temp("party_number")-1);
   obj->delete_temp("id");
   obj->delete("describe");
   return 1;
}
void die()
{
   string myid;
   object me;
   if(myid = this_object()->query_temp("id"))
      if( me = find_player(myid))
          me->set_temp("party_number", me->query_temp("party_number")-1);
   ::die();
}
int order_npc(string arg)
{
   mapping std_cmds =([
        "wield"     :  1,
        "unwield"   :  2,
        "wear"      :  3,
        "remove"    :  4,
        "follow"    :  5,
        "kill"      :  6,
        "surrender" :  7,
        "say"       :  8,
	"get"	    :  9,
	"drop"      : 10,
        ]);
   object me,obj;
   string npc_name,str1,verb,act,re;
   string cmd1;
   me = this_player();
    if( !arg ) return notify_fail("指令格式 : order <npc> do <command>\n\n");
   if( sscanf(arg,"%s do %s",npc_name,str1) != 2)
       return notify_fail("\n指令格式﹕order <npc> do <command>\n\n");
   if( this_object() != (obj = present(npc_name,environment(me))))
       return notify_fail("你要命令誰？\n");
   if( me->query("id") != obj->query_temp("id"))
       return notify_fail("別傻啦, 他又不是你的組員...\n");
   if( sscanf(str1,"%s %s",verb,act) != 2) {
      verb = str1;
      act = "";
      }
 
   else if(!std_cmds[verb] && !query("npc_cmds/"+verb))
        return notify_fail("\n我不懂你的意思耶! 你要我幫你做什麼事呀？\n");
 
   if(me->query("class")=="officer")
       tell_object(me,CYN + " 遵命! 大人! 小的立刻就辦。\n\n" + NOR);
   else
       tell_object(me,CYN + " 是的! 大俠! 這沒問題的啦！\n\n" + NOR);
 
   if( verb == "kill" && stringp(cmd1 = find_command(verb)) ) {
       message_vision(
       CYN + "$N說道﹕"+obj->name()+"! 就讓我們一起合攻他吧!\n\n" + NOR,me);
       call_other(cmd1,"main",me,act);
      }
   command(verb+" "+act);
 
   return 1;
}

void init()
{
   :: init();
   add_action("party_with","party");
   add_action("unparty","unparty");
   add_action("order_npc","order");
}
 
 
