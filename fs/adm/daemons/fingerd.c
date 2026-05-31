// fingerd.c
// 之前的改法太差了.....我重改...by chan
#include <origin.h>
#include <ansi.h>
#include <net/dns.h>
inherit F_CLEAN_UP;

varargs string remote_finger_user(string name);

void create() { seteuid( getuid() ); }

string age_string(int time)
{
        int month, day, hour;

        time /= 3600;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "個 月 ":"") + (day?day + " 天 ":"") + hour +"個 小時";
}

string finger_all()
{
        object *ob;
        string msg;
        int i;

        ob = users();
        msg = "";
        for(i=0; i<sizeof(ob); i++)
                // if(wiz_level(this_player())>3||(!wizardp(this_player())&&!wizardp(ob[i]))||(wiz_level(this_player())<4&&wizardp(this_player())&&wizardp(ob[i])))
//                if(wiz_level(this_player())||(!wizardp(this_player())&&!wizardp(ob[i])))
if(wizardp(this_player()))
{
	if (wiz_level(this_player()) < wiz_level(ob[i]) ) continue;
                msg = sprintf("%s%-20s  %-20s  %-10s %s\n",
                        msg, ob[i]->query("name"), ob[i]->query("id"),
                        age_string( (int)ob[i]->query("mud_age")), query_ip_name(ob[i]) );
}
      else  
{
        if (wiz_level(this_player()) < wiz_level(ob[i]) ) continue;
	msg = sprintf("%s%-20s  %-20s  %-10s\n",msg, ob[i]->query("name"), ob[i]->query("id"),age_string( (int)ob[i]->query("mud_age")));
}
      return msg;
}

varargs object acquire_login_ob(string name)
{
        object ob, body;

        ob = find_player(name);
        if (!ob){
                ob = new(LOGIN_OB);
                ob->set("id", name);
                if (!ob->restore()) {
                  destruct(ob); 
                  return ob;
                }
                body = LOGIN_D->make_body(ob);
                if (body->restore()) {
                  return body;
                }
                else {
                  destruct(ob);
                  destruct (body);
                  return ob;
                }
        }

        return ob;
}

string finger_user(string name)
{
        object me, ob, body;
        object where;
        string msg, mud;

        me = this_player();
        if (!name) ob = me;
        else if( sscanf(name, "%s@%s", name, mud)==2 ) {
                GFINGER_Q->send_finger_q(mud, name, this_player(1));
                return "網路指令傳送過程可能需要一些時間﹐請稍候。\n";
        }
        // ob = new(LOGIN_OB);
        // ob->set("id", name);
        else ob = find_player(name);
//      if( wiz_level(me) < wiz_level(ob) )
//              return "\n";
        if (!ob && wizardp(me) )
                return remote_finger_user(name);
        ob = acquire_login_ob(name);

        if( !ob )
         return "沒有這個玩家。\n";
//      if (!user(ob)) return "沒有這個玩家: "+name+"\n。";
        msg =  sprintf("\n英文代號﹕\t%s\n姓    名﹕\t%s\n權限等級﹕\t%s\n"
          "上次連線時間﹕\t%s\n上線時間總和﹕\t%s\n\n",
                ob->query("id"),
                ob->query("name"),
                SECURITY_D->get_status(name),
                ctime(ob->query("last_on")),
                age_string (ob->query("mud_age")),
        );
if(wizardp(this_player()))
msg += sprintf("上次連線位置﹕%s\n",ob->query("last_from"));
        msg += sprintf ("年齡是: %d 歲\n",
                ob->query("age"));

         if(SECURITY_D->get_status(name)==("player") && stringp(ob->query("clan/name")) )
        msg += sprintf("所屬幫派: %s\n",
                ob->query("clan/name"));

       if(ob->query("new_mail"))
        msg += sprintf("他有新的情書未讀\n");
        if( wiz_level(me) < wiz_level(ob) )
            return msg;
        where = environment(ob);
        if (where && wizardp(me))
        msg += sprintf("%s (%s) 現在在--%s (%s).\n",
                (string)ob->name(),
                (string)ob->query("id"),
        where ? where->query("short") : "未知",
                (string)file_name(where));
        else
        msg += sprintf("%s現在在--%s.\n",
                (string)ob->name(),
                where ? where->query("short") : "未知");

         if( objectp(body = find_player(name)) && geteuid(body)==name ) {
               if(wizardp(this_player()))
                msg += sprintf("%s 目前正在從 %s 連線中。\n", body->name(1),
                        query_ip_name(body));
 else msg += sprintf("目前正在連線中。\n");
        }
        if( stringp(ob->query("plan")) )
        msg += sprintf("%s 最近的計劃是--\n%s", name, ob->query("plan"));
        
        // destruct(ob);
        return msg;
}


object test(string name)
{
        object ob, body;
        string msg;

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() )
                return 0;
        body = LOGIN_D->make_body(ob);
if (!body->restore()) return 0;

  printf ("passwd: %s, %s\n", ob->query("password"), body->query("password"));
  return ob;
}

varargs string remote_finger_user(string name)
{
        object ob, body,me;
        string msg;
        me = this_player();
        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() )
                return "沒有這個玩家。\n";
        body = LOGIN_D->make_body(ob);
        if (body->restore()) ob = body;
        msg =  sprintf(
                "\n英文代號﹕\t%s\n姓    名﹕\t%s\n權限等級﹕\t%s\n"
                "上次連線地址﹕\t%s( %s )\n",
                ob->query("id"),
                ob->query("name"),
                SECURITY_D->get_status(name),
                ob->query("last_from"),
                ctime(ob->query("last_on"))
        );
        msg += sprintf ("年齡是: %d\n",
                ob->query("age"));

        if( stringp(ob->query("clan/name")) )
        msg += sprintf("所屬幫派: %s\n",
                ob->query("clan/name"));

        if( wiz_level(me) < wiz_level(ob) )
            return msg;

        if (ob->query_temp("terminal_type"))
           msg += sprintf ("terminal type is : %s\n",
                ob->query_temp("terminal_type"));


        if( find_player(name) )
                msg +=  "\n" + ob->query("name") + "目前正在線上。\n";

        if( stringp(ob->query("plan")) )
                msg += sprintf("%s 最近的計劃是--\n%s", name, ob->query("plan"));
        destruct(ob);
        return msg;
}
