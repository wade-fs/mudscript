// recruit.c
// Modify By Oda  把叛師的處罰放到 /feature/apprentice.c 裡面, 以免拜 npc
//                時處罰不到.

#include <ansi.h>
#define LEAST_RELATIONSHIP 1000
int ppl_ppl(object me,object ob);
int mailto_master(object me,object ob,int old);
int mail_to_old(object me,object ob);
inherit F_CLEAN_UP;

mapping *mails;

int main(object me, string arg)
{       
	object ob, old_rec;
	mapping family;
seteuid(getuid());

	if( !arg ) return notify_fail("指令格式﹕recruit [cancel]|<對象>\n");

	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("你現在並沒有收錄任何人為弟子的意思。\n");
		write("你改變主意不想收" + old_rec->name() + "為弟子了。\n");
		tell_object(old_rec, me->name() + "改變主意不想收你為弟子了。\n");
		me->delete_temp("pending/recruit");
		return 1;
	}
  if(me->query("horse")==1)
return notify_fail("馬不能收徒。\n");
	if( !(ob = present(arg, environment(me))) )
		return notify_fail("你想收誰作弟子﹖\n");

	if( ob==me ) return notify_fail("收自己為弟子﹖好主意....不過沒有用。\n");
	if( ob->is_apprentice_of(me) ) {
		message_vision("$N拍拍$n的頭﹐說道﹕「好徒兒﹗」\n", me, ob);
		if(ob->query("family/master_name")!=me->query("name")) ob->set("family/master_name",me->query("name"));
		return 1;
	}

	if( userp(ob) && userp(me) ) {
	if( ob->query("人際關係/"+me->query("id")) < LEAST_RELATIONSHIP )
		return notify_fail(ob->name()+"跟你的關係不夠好，你不能夠收他為徒。\n");
	}

	if( !me->query("family") )
		return notify_fail("你並不屬於任何門派﹐你必須先加入一個門派﹐或自己創一個才能收徒。\n");

	// If the target is willing to apprentice us already, we do it.
	if( (object)ob->query_temp("pending/apprentice") == me ) {

		if( !living(ob) ) {
			message_vision(
				"$N決定收$n為弟子。\n\n"
				"不過看樣子$n顯然沒有辦法行拜師之禮。\n\n",
				me, ob);
			return 1;
		}

		if( ob->query("family") ) {
			message_vision(
				"$N決定背叛師門﹐改投入$n門下﹗﹗\n\n"
				"$N跪了下來向$n恭恭敬敬地磕了四個響頭﹐叫道﹕「師父﹗」\n\n",
				ob, me);
			if( ob->query("人際關係/"+ob->query("family/master_id"))) ob->delete("人際關係/"+ob->query("family/master_id"));
			if( ob->query("family/master_is_ppl") ) mail_to_old(me,ob);
			if( !wizardp(ob) && userp(me) && ob->query("id")!="guest" ) log_file("apprentice",sprintf("%s(%s)改拜%s的%s(%s)為師於%s\n",ob->name(1),ob->query("id"),me->query("family/family_name"),me->name(1),me->query("id"),ctime(time())));
		} else {
			message_vision(
				"$N決定收$n為弟子。\n\n"
				"$n跪了下來向$N恭恭敬敬地磕了四個響頭﹐叫道﹕「師父﹗」\n",
				me, ob);
			if( !wizardp(ob) && userp(me) && ob->query("id")!="guest" ) log_file("apprentice",sprintf("%s(%s)拜%s的%s(%s)為師於%s\n",ob->name(1),ob->query("id"),me->query("family/family_name"),me->name(1),me->query("id"),ctime(time())));
                }
		if( userp(ob) && userp(me) ) {
		  if(me->query("family/master_is_ppl")) mailto_master(me,ob,0);
		  if(ob->query("id")!="guest") ppl_ppl(me,ob);
		}
		
		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");

		write("恭喜你新收了一名弟子﹗\n");
		family = ob->query("family");
		tell_object( ob, sprintf("恭喜您成為%s的第%s代弟子。\n", family["family_name"], chinese_number(family["generation"]) ));

                if(userp(me))   ob->set("family/master_is_ppl",1);
                else ob->delete("family/master_is_ppl");
		return 1;
	
	} else {

		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
			return notify_fail("你想收" + ob->name() + "為弟子﹐但是對方還沒有答應。\n");
		else if( objectp(old_rec) ) {
			write("你改變主意不想收" + old_rec->name() + "為弟子了。\n");
			tell_object(old_rec, me->name() + "改變主意不想收你為弟子了。\n");
		}

		me->set_temp("pending/recruit", ob );
		message_vision("\n$N想要收$n為弟子。\n", me, ob);
		tell_object(ob, YEL + "如果你願意拜" + me->name() + "為師父﹐用 apprentice 指令。\n" + NOR);
		return 1;
	}
}
int mail_to_old(object me,object ob)
{
 string ID;
 object user,old_master;
 ID = ob->query("family/master_id");
 if( FINGER_D->acquire_login_ob(ID) ) {
   if( !find_player(ID)) {
     user="/adm/daemons/cappointd.c"->get_user_ob(ID);
     old_master="/adm/daemons/cappointd.c"->get_user_body(user);
     old_master->set_temp("link_ob", user);
     old_master->setup();
     if(sizeof(all_inventory(old_master))) all_inventory(old_master)->set("autoload",1);
     if( old_master->query("人際關係/"+ob->query("id"))) old_master->delete("人際關係/"+ob->query("id"));
     old_master->save();
     //destruct(old_master);
   }
   else {
     old_master=find_player(ID);
     if( old_master->query("人際關係/"+ob->query("id"))) old_master->delete("人際關係/"+ob->query("id"));
   }
 }
 mailto_master(me,ob,1);
 return 1;
}

int ppl_ppl(object me,object ob)
{
 int i;
 object where;
 where = environment(ob);
 i=random(5);
 if(i==0)
 {
  tell_object(users(), HIC + "\n~~號外 號外~~\n\n\t" + HIW + me->query("family/family_name") +HIB + " 的 " + HIW + me->query("name") + HIY + " 收了一個新弟子 " + HIW+ ob->query("name")+HIG + "\n\n\t\t\t讓我們為 " + HIW+ me->query("family/family_name") +HIG + " 的壯大而喝采吧\n" + NOR + "\n");
 }
 else if(i==1)
 {
  tell_object(users(), HIY + "\n在歷經多年的奮鬥後\n\n\t" + HIW + me->query("family/family_name") + HIB + " 的 " + HIW + me->query("name") + HIG + " 終於成宗立派\n\n\t\t\t" + HIR + "並記取 " + HIW+ ob->query("name") +HIR + " 為其嫡傳弟子\n" + NOR + "\n");
 }
 else if(i==2)
 {
  tell_object(users(), HIW + where->query("short") + HIC + " 傳來一陣喝采\n\n\t" + HIY + "只見 " + HIW + ob->query("name") + HIY + " 跪地斟茶\n\n\t\t" + HIY + "正式拜 " + HIW + me->query("family/family_name") + HIB + " 的 " + HIW+ me->query("name")+HIY + " 為師學習武學\n" + NOR + "\n");
 }
 else if(i==3)
 {
  tell_object(users(), HIR + "\n無數戰鬥後\n\n\t" + HIW + ob->query("name") + HIM + " 終於獲得 " + HIW + me->query("family/family_name") + HIB + " 的 "+ HIW+ me->query("name")+ HIG + " 認可\n\n\t\t" + HIC + "得與於  " + HIW + me->query("name")+HIC + " 下拜師學藝\n" + NOR + "\n");
 }
 else
 {
  tell_object(users(), HIC + "\n~~狂賀 狂賀~~\n\n\t" + HIW + me->query("family/family_name") + HIB + " 的 " + HIW + me->query("name") + HIY + " 正式收了 " + HIW+ ob->query("name")+HIY + " 為弟子了\n\n\t\t\t" + HIG + "大家來為 " + HIW+ob->query("name")+HIG + " 成為米蟲來大聲恭喜吧\n" + NOR + "\n");
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
 if(old==0 && ob->query("id")==me->query("family/master_id")) circle=1;
 if(old==0) {
   master=find_player(me->query("family/master_id"));
   if(!master) {
     if(!master= FINGER_D->acquire_login_ob(me->query("family/master_id")))
       circle=1;
     else d=1;
   }
 }
 else {
   old_ID=sprintf(" %s(%s)",ob->query("family/master_name"),ob->query("family/master_id"));
   master=find_player(ob->query("family/master_id"));
   if(!master) {
     if(!master= FINGER_D->acquire_login_ob(ob->query("family/master_id")))
       circle=1;
     else d=1;
   }
 }
 if(master && me->query("class") != master->query("class"))
  circle=1;
 else
 {
  if(!me->query("clan/name")) clan1=" ";
  else if(old==0) clan1=sprintf(" 幫派為 %s ",me->query("clan/name"));
  else clan1=sprintf("幫派為 %s 的 ",me->query("clan/name"));
  if(!ob->query("clan/name")) clan2=" ";
  else if(i==0) clan2=sprintf("幫派為 %s 的 ",ob->query("clan/name"));
  else clan2=sprintf(" 幫派為 %s ",ob->query("clan/name"));
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
          "text": "你在 "+me->query("family/family_name")+clan1+"的第"+j+"代徒弟 "+me->query("name")+"("+me->query("id")+")"+"為你收了一個徒孫"+clan2+ob->query("name")+"("+ob->query("id")+")於"+ctime(time())
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
          "text": "你在 "+ob->query("family/family_name")+clan2+"的第"+j+"代徒弟 "+ob->query("name")+"("+ob->query("id")+")"+"決定離開"+k+"另拜"+clan1+me->query("name")+"("+me->query("id")+")於"+ctime(time())
       ]);
     }
     if(master->query("id")!=ob->query("id") && master->query("id")!=me->query("id")) {
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
指令格式 : recruit [cancel]|<對象>
指令說明 :
           這個指令能讓你收某人為弟子，如果對方也
           答應要拜你為師的話。
           此外，拜玩家為師的話，彼此間的人際關係要夠才行。
HELP
        );
        return 1;
}
