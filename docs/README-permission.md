# 基本想法
## Role
- god
- wizard
- user
## ACL
- 管理哪些人可以寫哪些目錄

# 步驟

## 第一步：玩家資料結構

玩家 object：
```
// /std/user.c

string role;
string *write_paths;
```
例如：
```
role = "god";

write_paths = ({
    "/",
});
```
wizard：
```
role = "wizard";

write_paths = ({
    "/domains/foo/",
    "/obj/",
});
```
一般 user：
```
role = "user";

write_paths = ({
    "/data/user/wade.o",
});
```

第二步：master.c 權限 API

你需要集中管理。

不要把 permission logic 散在 driver。

建立：

// /secure/master/permission.c

或直接：

/master.c

先簡單即可。

第三步：核心 API
role 查詢
string query_role(string user);
path permission
int valid_write(string path, object user, string func);
int valid_read(string path, object user, string func);

這是 LP 傳統做法。

第四步：driver 只做 callback

Go driver：

res := d.CallFunction(masterObj, "valid_write", ...)

不要在 Go 裡做 ACL 邏輯。

全部交給 LPC。

這非常重要。

因為：

security policy 應該在 mudlib

不是 driver。

driver 只做 enforcement。

第五步：權限判斷
god
if (role == "god")
    return 1;
wizard
foreach (string p in write_paths) {
    if (strsrch(path, p) == 0)
        return 1;
}
user

只能：

/data/user/<id>.o
第六步：第一個玩家變 god

登入建立角色：

string *users = get_dir("/data/user/*.o");

if (!sizeof(users)) {
    role = "god";
    write_paths = ({ "/" });
}

這其實就是你原本概念。

第七步：delegation

你需求：

wizard 可以指定別人擁有自己授權的目錄的寫入權

這代表：

wizard 可以 delegate 自己 subset 的 path

例如：

wizard 擁有：

/domains/foo/
/obj/

那只能授權：

/domains/foo/bar/

但不能：

/secure/
最簡單實作

God command：

promote user wizard
demote user
grant user /path/
revoke user /path/

Wizard command：

grant user /mydomain/

但：

if (!has_write_access(this_player(), path))
    return 0;
第八步：不要直接存 path 到 master

你應該：

permission 跟 player 綁定

因為：

persistence 簡單
restore 自然
不用額外 database
第九步：建議的 LPC API
/std/user.c
string query_role();
void set_role(string role);

string *query_write_paths();

int add_write_path(string path);
int remove_write_path(string path);

int has_write_access(string path);
master.c
int valid_write(string path, object user, string func);
第十步：valid_write 範例
int valid_write(string path, object user, string func)
{
    string *paths;

    if (!user)
        return 0;

    if (user->query_role() == "god")
        return 1;

    paths = user->query_write_paths();

    foreach (string p in paths) {
        if (strsrch(path, p) == 0)
            return 1;
    }

    return 0;
}
第十一步：防止 wizard 升自己

God-only command：

if (target == this_player())
    return notify_fail("不能修改自己的權限。\n");
第十二步：你之後一定會需要的

現在先別做。

但 architecture 要留：

group / domain system

傳統：

/domains/foo/
/domains/bar/

每個 domain：

domain lord
wizard list
apprentice

但這可以第二階段。

最重要的設計原則
Driver 不懂 security policy

Driver 只：

問 master:
能不能寫？

然後：

master 回答 yes/no

這是 LP MUD 非常核心的設計哲學。
