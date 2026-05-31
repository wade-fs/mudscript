// summon command..
// Closed by wade Tue Sep 26 1995

inherit F_CLEAN_UP;

int main(object me, string str)
{
  object ob;
  string wiz;

  ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("咦... 有這個人嗎?\n");
  wiz = (string)wizhood (me);
  // 請勿隨便 summon 別人
  if ( (!wizardp(ob) && ob->query("id")!="guest" && wiz_level(me)<4) || wiz_level (me) < wiz_level (ob) )
    return notify_fail ("【系統】: 隨便 Summon 別人是不禮貌的, 還是用 goto 吧!!\n");
  else {
        if (!str) return notify_fail("語法: summon <玩家的英文名>\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("咦... 有這個人嗎?\n");
        // moving
        if (environment(ob)) {
          log_file("static/SUMMON",
          sprintf ("%s - 抓 - <%s>\n%s -- 抓到 --> %s\n%s\n\n",
                me->short(), ob->short(),
                file_name(environment(ob)),
                file_name(environment(me)),
                ctime(time())));
          tell_room(environment(ob),"天空中伸出一隻大手把"+
          (string)ob->query("name")+"抓了起來, 然後不見了.\n", ob);
        }
        tell_object(ob,"一隻手把你抓了起來, 你眼前一陣黑....\n");
        ob->move(environment(me));
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
        tell_object(ob,".... 醒來時發現是"+(string)me->query("name")+
        "把你弄過來的.\n");
        tell_room(environment(ob),(string)ob->query("name")+"突然出現"+
        "在你眼前\n",({me,ob}));
        // ok ..
        return 1;
  }
}

