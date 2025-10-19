### **一、简答题**
**1. 后端开发**
- **请简单阐述后端开发是什么？**
    后端开发就是构建运行在服务器上的各种复杂逻辑，完成各种功能。
- **后端开发的核心职责是什么？**
  处理业务逻辑、管理数据库、设计和开发API、管理服务器、保证数据安全。
- **后端与前端通过什么方式进行协作交互？**
  前段通过调用后端设计好的API实现各种功能。

**2. API**
- **请简单阐述 API 是什么？**
  API是调用具体功能的入口，规定了怎样使用以及设计好的功能。
- **API 的核心作用是什么？**
  使我们在编写程序时，不需要完全理解整个功能实现的底层逻辑，而只需要懂得如何使用，大大降低了学习门槛。
- **API 返回的数据为什么通常是 JSON 格式？**
  JSON格式的数据结构是双列集合，每个元素就是简单的键值对，即利于人类阅读，又利于及其解析；同时，JSON数据体积小、支持几乎所有主流语言，使其成为绝对主流的数据格式。

**3. 数据库**
- **请简单阐述数据库是什么？**
  数据库是按照数据结构来组织、存储和管理数据的仓库。
- **为什么用户信息存储在数据库中而不存储在用户电脑中？**
  **1.** 存在用户电脑中，一旦设备损坏，数据也会丢失，而存在数据库中时数据安全得到保障；
  **2.** 存在数据库中便于服务器统一管理，有利于处理需要用户数据的各项功能。
- **对于数据库中的数据，有哪些基础操作？**
  主要有 **CRUD：** 
  - **C：** Create（创建）；
  - **R：** Read（读取）；
  - **U：** Update（更新）；
  - **D：** Delete（删除）。
### 三、 代码阅读题：任务处理（Java）
**1. 给出程序的运行结果**
![alt text](搜狗截图20251002225711-1.png)
**2. Processable、Task 和 SendEmailTask 三者之间是什么关系？**
- Processable是最顶层的接口；Task是Processable的实现类；SendEmailTask是Task的子类，通过多层继承也实现了Processable接口。
**3. 解释 TaskProcessor 的 process 方法中的每一行代码的作用**
```java
package net.mioyi;

import java.util.Collections;
import java.util.stream.StreamSupport;

public class TaskProcessor implements Processor {
    @Override
    public void process(Iterable<Processable<?>> processables) { //应用多态，传入Iterable的实现类对象
        StreamSupport.stream(processables.spliterator(), false) //生成Stream流，明确表示其不是并行流,?
                .filter(Task.class::isInstance) //使用isInstance判断元素是否为Task类的对象（包括其子类对象），过滤流中的元素。只保留Task类的对象
                .map(Task.class::cast)  //使用cast方法，将过滤后的Task类的对象（其实是Task的子类对象）转换为Task类的对象
                .filter(task -> task.getStatus() == Task.Status.PENDING) //过滤出待处理的任务
                .sorted(Collections.reverseOrder()) //对剩余任务进行降序排序
                .map(Task::process) //对每个任务调用process方法处理并返回结果
                .forEach(System.out::println);  //打印所有处理结果
    }
}
```
**4. 在 Task 中，id 字段由 private static final AtomicLong counter 生成。为什么要加 static？去掉static 后会怎么样？**
- 用static修饰使该类所有对象共用一个计数器，确保了id的唯一性。去掉后每创建一个对象计数器都重新开始计数，导致每个对象id都是0。
**5. 在 Processor 的 process 方法参数中，为什么使用的是 Iterable<Processable <?>> 而不是Iterable<Processable\<Object>> 或Iterable\<Processable>？**
- 使用Iterable<Processable <?>>有两个好处，一是保证编译安全，二是灵活度高；
- 相比于Iterable\<Processable>，Iterable<Processable <?>>多了一个泛型检查；前者是可编译可执行，但运行时可能报错，后者是编译时就会发出警告，提醒你这里可能会转换失败，让你检查程序逻辑以确保运行成功；
- 相比于Iterable<Processable\<Object>>，Iterable<Processable <?>>更加灵活；Iterable<Processable\<Object>>只能传入Object类型，传入其他类型就会报错，如源代码中Task子类实现的是Task<String>,String类型不能自动转换成Object类型，所以会报错。