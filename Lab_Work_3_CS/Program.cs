using System;
using System.Collections;
using System.Collections.Generic;

namespace Lab_Work_3_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            LinkedListlinkedList<string> linkedList = new LinkedListlinkedList<string>();
            linkedList.Add("0");
            linkedList.Add("4");
            linkedList.Add("1645hfg7u657rtygj5niuy");
            linkedList.Add("1645hfg7u657rtygj5niuy");
            linkedList.Add("8vchgffd");
            linkedList.Add("8vchgffd");
            linkedList.Add("1645hfg7u657rtygj5niuy");
            linkedList.Add("1645hfg7u657rtygj5niuy");
            linkedList.Add("8vchgffd");
            linkedList.Add("8vchgffd");
            
            linkedList.Add("8vchgffd");
            linkedList.Add("8");
            linkedList.Add("3");
            linkedList.Add("8");
            linkedList.Add("35");
            SortLinkedList.Sort(linkedList);
            linkedList.Print();
        }
    }

    public static class SortLinkedList
    {
        public static void Sort<T>(LinkedListlinkedList<T> linkedList) where T: IComparable
        {
            for (int i = 0; i < linkedList.Length; i++)
            {
                for (int j = i + 1; j < linkedList.Length; j++)
                {
                    if (linkedList[i].CompareTo(linkedList[j]) > 0)
                    {
                        linkedList.SwapValue(linkedList.GetNodeByIndex(i), linkedList.GetNodeByIndex(j));
                    }
                }
            }
        }
    }

    public class LinkedListEnumerator<T> : IEnumerator
    {
        private LinkedListlinkedList<T> list;
        private int position = -1;
        public LinkedListEnumerator(LinkedListlinkedList<T> linkedList)
        {
            list = linkedList;
        }
        public object Current
        {
            get
            {
                if (position == -1 || position > list.Length)
                {
                    throw new InvalidOperationException();
                }
                return list[position];
            }
        }
        public bool MoveNext()
        {
            bool result = false;
            if (position < list.Length - 1)
            {
                result = true;
                position++;
            }
            return result;
        }

        public void Reset()
        {
            position = -1;
        }
    }
    public class LinkedListlinkedList<T> : IEnumerable
    {
        private Node<T> FirstNode = null;

        private int _length = 0;

        public Node<T> GetNodeByIndex(int index)
        {
            Node<T> current = FirstNode;
            Node<T> result = null;
            int count = 0;
            if (index >= Length || index < 0)
            {
                throw new IndexOutOfRangeException();
            }
            do
            {
                if (index == count)
                {
                    result = current;
                    break;
                }
                current = current.Next;
                count++;
            }
            while (current != FirstNode);
            return result;
        }

        public void SwapValue(Node<T> n1, Node<T> n2)
        {
            T temp = n1.Value;
            n1.Value = n2.Value;
            n2.Value = temp;

        }
        public T this[int index]
        {
            get
            {
                int countIndex = 0;
                Node<T> ptr = FirstNode;
                T result = default;
                if (index >= Length || index < 0)
                {
                    throw new IndexOutOfRangeException();
                }
                while (ptr != null)
                {
                    if (countIndex == index)
                    {
                        result = ptr.Value;
                        break;
                    }
                    ptr = ptr.Next;
                    countIndex++;
                }
                return result;
            }
            set
            {
                int countIndex = 0;
                Node<T> ptr = FirstNode;
                if (index >= Length || index < 0)
                {
                    throw new IndexOutOfRangeException();
                }
                while (ptr != null)
                {
                    if (countIndex == index)
                    {
                        ptr.Value = value;
                        break;
                    }
                    ptr = ptr.Next;
                    countIndex++;
                }
            }
        }

        public int Length
        {
            get
            {
                return _length;
            }
        }

        public void Print()
        {
            foreach(var node in this)
            {
                Console.WriteLine(node);
            }
        }

        public void Add(T data)
        {
            Node<T> node = new Node<T>(data);

            if (FirstNode == null)
            {
                FirstNode = node;
                FirstNode.Next = node;
                FirstNode.Previous = node;
            }
            else
            {
                node.Previous = FirstNode.Previous;
                node.Next = FirstNode;
                FirstNode.Previous.Next = node;
                FirstNode.Previous = node;
            }
            _length++;
        }

        public IEnumerator GetEnumerator()
        {
            return new LinkedListEnumerator<T>(this);
        }
    }
    public class Node<T>
    {
        public T Value { get; set; }
        public Node<T> Next { get; set; } = default;
        public Node<T> Previous { get; set; } = default;
        public Node(T value)
        {
            Value = value;
        }
    }
}
