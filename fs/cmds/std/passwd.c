// passwd.c

inherit F_CLEAN_UP;

int check_passwd (string);
void create() { seteuid(getuid());}

int main(object me, string arg)
{
  object ob;

  if( me != this_player(1) ) return 0;

  ob = me->query_temp("link_ob");
  if( !ob ) return 0;
  while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

  write("為了安全起見﹐請先輸入您原來的密碼﹕");
  input_to("get_old_pass", 1, ob);
  return 1;
}
void get_old_pass(string pass, object ob)
{
  string old_pass;

  write("\n");
  old_pass = ob->query("password");
  if( crypt(pass, old_pass)!=old_pass ) {
    write("密碼錯誤﹗\n");
    return;
  }
  write("請輸入新的密碼﹕");
  input_to("get_new_pass", 1, ob );
}

void get_new_pass(string pass, object ob)
{
  if (!check_passwd (pass)) {
    write ("密碼必須至少含有一個普通英文字母跟一個非普通英文字母.\n");
    write("\n請再輸入一次新的密碼﹕");
    input_to("get_new_pass", 1, ob );
  }
  else {

    write("\n請再輸入一次剛剛的密碼，以資確認﹕");
    input_to("confirm_new_pass", 1, ob, crypt(pass,0));
  }
}

void confirm_new_pass(string pass, object ob, string new_pass)
{
  write("\n");
  if( crypt(pass, new_pass)!=new_pass ) {
    write("對不起﹐您輸入的密碼並不相同﹐繼續使用原來的密碼。\n");
    return;
  }
  if( !ob->set("password", new_pass) ) {
    write("密碼變更失敗﹗\n");
    return;
  }
  ob->save();
  write("密碼變更成功\。\n");
}
//修改by bss
//我只會用笨方法
int check_passwd (string passwd)
{
  int   i, n, word,cnt;
  string txt;
  if ((n = strlen (passwd)) < 5) return 0;

  cnt=0;
  for(i=0;i<sizeof(passwd);i++)
  {
    txt=sprintf("%d",passwd[i]);
    sscanf(txt,"%d",word);
    if((word <= 122 && word >= 97) ||
       (word <= 90 && word >= 65))
      cnt++;
  }
  if(!cnt) return 0;
  else if(cnt==sizeof(passwd)-1) return 0;
  else return 1;

}
int help(object me)
{
  write(@HELP
指令格式 : passwd
指令說明 :
           這個指令可以修改你的人物密碼。
         密碼的目的是在保護自己的人物不被他人任意使用，因此，
         必須適當的設定密碼。通常密碼不得過於簡單。系統基本上
         會要求你不能使用下列情形當密碼：
             1.  太短，目前設定是不能比五個字元短。

             2.  全部都是英文字，至少必須包括數字或特殊符號。
             3.  全部都是特殊符號，如全部都是數字。
HELP
    );
    return 1;
}
