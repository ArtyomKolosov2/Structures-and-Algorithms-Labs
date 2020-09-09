using System;
using System.Collections;
using System.Collections.Generic;

namespace Lab_Work_3_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            LinkedListStudy<string> study = new LinkedListStudy<string>();
            study.AddAtFront("Hello");
            study.AddAtBack("World");
            study.Print();
        }


    }

    public class LinkedListEnumerator<T> : IEnumerator
    {
        private LinkedListStudy<T> list;
        private int position = -1;
        public LinkedListEnumerator(LinkedListStudy<T> linkedList)
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
    public class LinkedListStudy<T> : IEnumerable
    {
        private Node<T> FirstNode = null;

        private Node<T> Tail = null;

        private int _length = 0;

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
            Node<T> ptr = FirstNode;
            int count = 1;
            if (Length != 0)
            {
                do
                {
                    Console.WriteLine($"{count.ToString()}: {ptr.Value.ToString()}");
                    count++;
                    ptr = ptr.Next;
                } while (ptr != Tail);
            }
        }

        public void AddAtFront(T value)
        {
            Node<T> node = new Node<T>(value);
            if (Length == 0)
            {
                FirstNode = Tail = node;
                FirstNode.Next = Tail;
                Tail = FirstNode;
            }
            else
            {
                node.Next = FirstNode;
                node.Previous = Tail;
                FirstNode = node;
            }
            _length++;
        }

        public void AddAtBack(T value)
        {
            Node<T> node = new Node<T>(value);
            if (Length == 0)
            {
                Tail = FirstNode = node;
                FirstNode.Next = Tail;
                Tail = FirstNode;
            }
            else
            {
                Node<T> ptr = FirstNode;
                while (ptr.Next != FirstNode)
                {
                    ptr = ptr.Next;
                }
                ptr.Next = node;
                node.Next = FirstNode;
                node.Previous = ptr;
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
