// apprentice.c
// Modify By Oda 96/6/5 將叛師對於技能之影響改寫到 /feature/apprentice.c 中
//                      避免在玩家拜 NPC 為師時有無法扣到的情形

#include <ansi.h>
#define LEAST_RELATIONSHIP 100
int ppl_ppl(object me,object ob);
int mailto_master(object me,object ob,int old);
int mail_to_old(object me,object ob);
inherit F_CLEAN_UP;
mapping *mails;

int main(object me, string arg)
{   
 	object ob, old_app;
        mapping family;
        mapping guild=([]),master=([]);

        seteuid(getuid());

	
        guild=GUILD_D->query_translate();
        if( !arg ) return notify_fail("指令格式﹕apprentice [cancel]|<對象>\n");
        arg = lower_case(arg);

        if( arg=="cancel" ) {
                old_app = me->query_temp("pending/apprentice");
                if( !objectp(old_app) )
                        return notify_fail("你現在並沒有拜任何人為師的意思。\n");
                write("你改變主意不想拜" + old_app->name() + "為師了。\n");
                tell_object(old_app, me->name() + "改變主意不想拜你為師了。\n");
                me->delete_temp("pending/apprentice");
                return 1;
        }

        if( !(ob = present(arg, environment(me))) )
                return notify_fail("你想拜誰為師﹖\n");

        if( ob==me ) return notify_fail("拜自己為師﹖好主意....不過沒有用。\n");
  if(me->query("horse")==1)
return notify_fail("馬不能拜師。\n");
if((me->query("family/family_name")=="魔刀門" || me->query("family/family_name")=="魔刀莫測") && ob->query("family/family_name")=="金刀門")
return notify_fail("你是魔刀人不能拜金刀為師！\n");
if((me->query("family/family_name")=="血魔一派" || me->query("swordskill/bloodz")) && ob->query("family/family_name")!="血魔一派")
  return notify_fail("你是血魔一派不能拜其他派為師！\n");

        if( me->is_apprentice_of(ob) ) {
                message_vision("$N恭恭敬敬地向$n磕頭請安﹐叫道﹕「師父﹗」\n", me, ob);
		if(me->query("family/master_name")!=ob->query("name")) me->set("family/master_name",ob->query("name"));
                return 1;
        }

        if( userp(ob) ) {
        if( me->query("人際關係/"+ob->query("id")) < LEAST_RELATIONSHIP )
                return notify_fail("你跟"+ob->name()+"的關係不夠好，你不能拜他為師。\n");
        //加入聖火的弟子不能拜玩家
        if(ob->query("class")=="prayer")
                return notify_fail("你是聖火教的弟子不能私下收授弟子\n");
        }

        if( !mapp( ob->query("family") ) )
                return notify_fail(ob->name() + "既不屬於任何門派﹐也沒有開山立派﹐不能拜師。\n");

        //增加可以限制某些人不能再收弟子
        if( ob->query("no_recruit")==1 )
                return notify_fail(ob->name()+"所屬的門派不准私下收授弟子。\n");

        if( me->query("class") != ob->query("class")
        || !me->query("class") || !ob->query("class") )
                return notify_fail("你的職業和他不同﹐他不願意收你。\n");

        // If the target is willing to recruit us already, we do it.
        if( (object)ob->query_temp("pending/recruit") == me ) {

                if( !living(ob) ) {
                        message_vision(
                                "$N決定拜$n為師﹖\n\n"
                                "$N跪了下來向$n恭恭敬敬地磕了四個響頭﹐叫道﹕「師父﹗」\n\n"
                                "但是看樣子$n並不知道有人跟他磕頭。\n",
                                me, ob);
                        return 1;
                }

                if( me->query("family") ) {
                        message_vision(
                                "$N決定背叛師門﹐改投入$n門下﹗﹗\n\n" 
                                "$N跪了下來向$n恭恭敬敬地磕了四個響頭﹐叫道﹕「師父﹗」\n\n",
                                me, ob);
                        me->set("secondapp",1);
			if( me->query("人際關係/"+me->query("family/master_id"))) me->delete("人際關係/"+me->query("family/master_id"));
			if( me->query("family/master_is_ppl") ) mail_to_old(me,ob);
	                if( !wizardp(me) && userp(ob) && me->query("id")!="guest" ) log_file("apprentice",sprintf("%s(%s)改拜%s的%s(%s)為師於%s\n",me->name(1),me->query("id"),ob->query("family/family_name"),ob->name(1),ob->query("id"),ctime(time())));
	        } else {
                        message_vision(
                                "$N決定拜$n為師。\n\n"
                                "$N跪了下來向$n恭恭敬敬地磕了四個響頭﹐叫道﹕「師父﹗」\n\n",
                                me, ob);
		        if( !wizardp(me) && userp(ob) && me->query("id")!="guest" ) log_file("apprentice",sprintf("%s(%s)拜%s的%s(%s)為師於%s\n",me->name(1),me->query("id"),ob->query("family/family_name"),ob->name(1),ob->query("id"),ctime(time())));
		}
                if( userp(ob) && userp(me) ) {
		  if(ob->query("family/master_is_ppl")) mailto_master(me,ob,0);
		  if(me->query("id")!="guest") ppl_ppl(me,ob);
		}
		 
                ob->recruit_apprentice(me);
                ob->delete_temp("pending/recruit");

                tell_object(ob, "恭喜你新收了一名弟子﹗\n");
                family = me->query("family");
                printf("恭喜您成為%s的第%s代弟子。\n", me->query("family/family_name"), chinese_number( me->query("family/generation")));
		if(userp(ob))   me->set("family/master_is_ppl",1);

                else me->delete("family/master_is_ppl");
                return 1;
        
        } else {

                old_app = me->query_temp("pending/apprentice");
                if( ob==old_app )
                        return notify_fail("你想拜" + ob->name() + "為師﹐但是對方還沒有答應。\n");
                else if( objectp(old_app) ) {
                        write("你改變主意不想拜" + old_app->name() + "為師了。\n");
                        tell_object(old_app, me->name() + "改變主意不想拜你為師了。\n");
                }

                message_vision("$N想要拜$n為師。\n", me, ob);
                me->set_temp("pending/apprentice", ob );
                if( userp(ob) ) {
                        tell_object(ob, YEL + "如果你願意收" + me->name() + "為弟子﹐用 recruit 指令。\n" + NOR);
                } else {
                        ob->attempt_apprentice(me);
                       }
                return 1;
        }
}

int mail_to_old(object me,object ob)
{
 string ID;
 object user,old_master;
 ID = me->query("family/master_id");
 if( FINGER_D->acquire_login_ob(ID) ) {
   if( !find_player(ID)) {
     user="/adm/daemons/cappointd.c"->get_user_ob(ID);
     old_master="/adm/daemons/cappointd.c"->get_user_body(user);
     old_master->set_temp("link_ob", user);
     old_master->setup();
     if(sizeof(all_inventory(old_master))) all_inventory(old_master)->set("autoload",1);
     if( old_master->query("人際關係/"+me->query("id"))) old_master->delete("人際關係/"+me->query("id"));
     old_master->save();
     //destruct(old_master);
   }
   else {
     old_master=find_player(ID);
     if( old_master->query("人際關係/"+me->query("id"))) old_master->delete("人際關係/"+me->query("id"));
   }
 }
 mailto_master(me,ob,1);
 return 1;
}

int ppl_ppl(object me,object ob)
{
 int i;
 object where;
 where =environment(ob);
 i=random(5);
 if(i==0)
 {
  tell_object(users(), HIY + "\n~~號外 號外~~\n\n\t" + HIW + ob->query("family/family_name") +HIB + " 的 " + HIW + ob->query("name") +HIC + " 收了一個新弟子 " + HIW+ me->query("name")+HIG + "\n\n\t\t\t讓我們為 " + HIW+ ob->query("family/family_name") +HIG + " 的壯大而喝采吧\n" + NOR + "\n");
 }
 else if(i==1)
 {
    tell_object(users(), HIY + "\n在歷經多年的奮鬥後\n\n\t" + HIW + ob->query("family/family_name") + HIB + " 的 " + HIW + ob->query("name") +HIG + " 終於成宗立派\n\n\t\t\t" + HIR + "並記取 " + HIW+ me->query("name") +HIR + " 為其嫡傳弟子\n" + NOR + "\n");
 }
 else if(i==2)
 {
    tell_object(users(), HIW + where->query("short") + HIC + " 傳來一陣喝采\n\n\t" + HIY + "只見 " + HIW + me->query("name") + HIY + " 跪地斟茶\n\n\t\t" + HIY + "正式拜 " + HIW + ob->query("family/family_name") + HIB + " 的 " + HIW+ ob->query("name")+HIY + " 為師學習武學\n" + NOR + "\n");
 }
 else if(i==3)
 {
    tell_object(users(), HIR + "\n無數戰鬥後\n\n\t" + HIW + me->query("name") + HIM + " 終於獲得  " + HIW + ob->query("family/family_name") + HIB + " 的 "+ HIW+ ob->query("name")+ HIG + " 認可\n\n\t\t" + HIC + "得與於  " + HIW + ob->query("name")+HIC + " 下拜師學藝\n" + NOR + "\n");
 }
 else
 {
  tell_object(users(), HIC + "\n~~狂賀 狂賀~~\n\n\t" + HIW + ob->query("family/family_name") + HIB + " 的 " + HIW + ob->query("name") + HIY + " 正式收了 " + HIW+ me->query("name")+HIY + " 為弟子了\n\n\t\t\t" + HIG + "大家來為 " + HIW+me->query("name")+HIG + " 成為米蟲來大聲恭喜吧\n" + NOR + "\n");
 }
 return 1;
}

int mailto_master(object me,object ob,int old)
{
 int circle=0,i,j=1,d=0;
 object mbox,master;
 mapping mail;
 string ID,clan1,clan2,old_ID,k;
 mixed ppl;
 if(old==0) {
   if(!sizeof(ppl)) {
     ppl=({me->query("id")});
     ppl+=({ob->query("id")});
   }
   else {
     ppl+=({me->query("id")});
     ppl+=({ob->query("id")});
   }
 }
 if(old==0 && me->query("id")==ob->query("family/master_id")) circle=1;
 if(old==0) {
   master=find_player(ob->query("family/master_id"));
   if(!master) {
     if(!master= FINGER_D->acquire_login_ob(ob->query("family/master_id")))
        circle=1;
     else d=1;
   }
 }
 else {
   master=find_player(me->query("family/master_id"));
   old_ID=sprintf(" %s(%s)",me->query("family/master_name"),me->query("family/master_id"));
   if(!master) {
     if(!master= FINGER_D->acquire_login_ob(me->query("family/master_id")))
       circle=1;
     else d=1;
   }
 }
 if(master && me->query("class") != master->query("class"))
  circle=1;
 else
 {
  if(!ob->query("clan/name")) clan1=" ";
  else if(old==0) clan1=sprintf(" 幫派為 %s ",ob->query("clan/name"));
  else clan1=sprintf("幫派為 %s 的 ",ob->query("clan/name"));
  if(!me->query("clan/name")) clan2=" ";
  else if (old==0) clan2=sprintf("幫派為 %s 的 ",me->query("clan/name"));
  else clan2=sprintf(" 幫派為 %s ",me->query("clan/name"));
 }
 while(master && !circle) {
     if(!sizeof(ppl)) ppl=({master->query("id")});
     else ppl+=({master->query("id")});

     mbox = new(MAILBOX_OB);
     mbox->set_owner(master->query("id"));
     if(old==0) {
       mail = ([
          "from": "狂想系統",
          "title": "收徒通知",
          "to": master->query("id"),
          "time": time(),
          "text": "你在 "+ob->query("family/family_name")+clan1+"的第"+j+"代徒弟 "+ob->query("name")+"("+ob->query("id")+")"+"為你收了一個徒孫"+clan2+me->query("name")+"("+me->query("id")+")於"+ctime(time())
       ]);
     }
     else {
       if(j==1) k="";
       else k=old_ID;
       mail = ([
          "from": "狂想系統",
          "title": "離門通知",
          "to": master->query("id"),
          "time": time(),
          "text": "你在 "+me->query("family/family_name")+clan2+"的第"+j+"代徒弟 "+me->query("name")+"("+me->query("id")+")"+"決定離開"+k+"改拜"+clan1+ob->query("name")+"("+ob->query("id")+")為師於"+ctime(time())
       ]); 
     }
     if(master->query("id")!=me->query("id") && master->query("id")!=ob->query("id")) {
       mbox->receive_mail(mail);
       if(find_player(master->query("id"))) {
         mbox = master->query_temp("mbox_ob");
         tell_object(master, GRN + "\n冰胖用千里傳音跟您說﹕有您的信﹗請去收信﹗\n\n" + NOR);
       }
       else MAIL_D->send_mail2(master->query("id"));
     }
     //destruct(mbox);
     if(master->query("family/master_is_ppl")) {
       ID=master->query("family/master_id");
       if(d) {
	 //destruct(master);d=0;
       }
       if(!master=find_player(ID)) {
         if(!master=FINGER_D->acquire_login_ob(ID)) circle=1;
         else d=1;
       }
     }
     else {
       circle=1;
       if(d) {
	 //destruct(master);d=0;
       }
     }
     j++;
     for(i=0;i<sizeof(ppl);i++)
        if(master->query("id")==ppl[i])
           circle=1;
     if(master && me->query("class") != master->query("class")) circle=1;
 }
 //if(d) destruct(master);
 return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : apprentice [cancel]|<對象>
指令說明 :
           這個指令能讓你拜某人為師﹐如果對方也答應要收你為徒的
         話﹐就會立即行拜師之禮﹐否則要等到對方用 recruit  指令
         收你為弟子才能正式拜師。
           如果對你的師父使用這個指令﹐會變成向師父請安。
特別注意 :
           請注意你已經有了師父﹐又背叛師門投入別人門下﹐所有技
         能會減半﹐並且評價會降到零。
 
請參考相關指令 expell、recruit
HELP
        );
        return 1;
}
