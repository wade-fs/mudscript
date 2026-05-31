inherit ROOM;


// 要能存檔的第一步：
inherit F_SAVE;

// 如不想存檔，要加 static 在最前面
mapping data=([
  "wade":       ({ "(04)6397291", "0920-351711", }),
]);

void create()
{
 seteuid(ROOT_UID);
 set("short","電話簿");
 set("long","簡單的電話簿，可以利用(add)來增加資料，
 如果你閒麻煩也可以直接用(ask)，當然也可以
 用(list)列出所有的資料, 或 (del) 刪除不要的記錄。\n");

   set("exits", ([ /* sizeof() == 1 */
        "back" : "/open/wiz/hall1",
   ]) );

 setup();
}

// 第三步
string query_save_file() {
  return DATA_DIR+"telphone/tel";
}

void init()
{
 add_action("do_add","add");
 add_action("do_ask","ask");
 add_action("do_list","list");
 add_action("do_del","del");
  // 第二步
  if (!restore()) save();
}

int do_del (string str)
{
  string who, tel;

  if (!str) return notify_fail ("del who [tel]\n");
  if (sscanf (str, "%s %s", who, tel) != 2) {
    who = str;
    map_delete (data, who);
  }
  else {
    if (arrayp (data[who]))
      data[who] -= ({ tel });
  }
  this_object()->save();
  return 1;
}

int do_add(string str)
{
 string who, tel;

 if(sscanf(str,"%s %s",who, tel)!=2)
  return notify_fail("輸入格式 add who tel\n"); 
 printf("新增 %s : %s 完畢\n", who, tel);
  if (!arrayp (data[who])) {
    map_delete (data, who);
    data[who] = ({ tel });
  }
  else
   data[who] += ({ tel });

  // 存檔第四步, 該存檔時就下底下的命令
  this_object()->save();
 return 1;
}
int do_ask(string str1)
{
 if(!data[str1]) return notify_fail("你的通訊錄中並無此人資料\n");
 printf("%s 的聯絡電話是：\n%O\n",str1,data[str1]);
 return 1;
}

int do_list()
{
 printf("通訊錄資料：\n");
 printf(" %O \n",data);
 printf("總共有 %d 筆資料\n",sizeof(data));
 return 1;
}
