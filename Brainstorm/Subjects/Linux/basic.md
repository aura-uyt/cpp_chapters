# Basics

## 1. Bare Metal Installation (Native Installation / Dual Boot)

This means Linux is installed **directly on your hardware**.

* **Single Boot:** Linux is the only OS installed.
* **Dual Boot:** Windows and Linux are both installed on separate partitions. At startup, a bootloader (usually **GRUB**) asks which OS you want to boot.

### Architecture

```bash
Hardware
    │
┌───┴──────────────┐
│                  │
Windows        Linux
```

**Pros**

* Full CPU, GPU, RAM, and disk performance.
* Direct access to hardware.
* Best for gaming, AI/ML, Docker, servers, development, etc.
* No virtualization overhead.

**Cons**

* Requires disk partitioning.
* Must reboot to switch between Windows and Linux.
* Slightly more complex to set up.

---

## 2. Virtual Machine (VM)

Here, Linux runs **inside Windows** as a virtual computer.

The software creating this virtual computer is called a **Hypervisor**.

Common hypervisors:

* Oracle VM VirtualBox (Type 2)
* VMware Workstation (Type 2)
* Microsoft Hyper-V (Type 1, integrated into Windows Pro/Enterprise)

### Architectures

```bash
Hardware
    │
Windows
    │
Hypervisor
    │
Linux VM
```

**Pros**

* No reboot required.
* Linux and Windows run simultaneously.
* Safe—if something breaks, delete the VM.
* Great for learning Linux, testing software, practicing commands.

**Cons**

* Uses part of your RAM and CPU.
* Graphics performance is limited.
* Not ideal for gaming or GPU-intensive tasks.

---

## Hypervisor Types

### Type 1 (Bare-Metal Hypervisor)

Installed **directly on hardware**.

```bash
Hardware
    │
Hypervisor
    │
Virtual Machines
```

Examples:

* VMware ESXi
* Microsoft Hyper-V (can operate as a Type 1 hypervisor)
* Xen Project

Used mainly in data centers and servers.

---

### Type 2 (Hosted Hypervisor)

Runs **as an application inside an existing operating system**.

```bash
Hardware
    │
Windows
    │
VirtualBox / VMware Workstation
    │
Linux VM
```

This is what most students and developers use.

---

## Which should you choose?

Since you're a CS student interested in C++, DSA, backend development, and eventually system design:

### Start with a Virtual Machine if

* You're just learning Linux.
* You don't want to risk your Windows installation.
* You want to use both OSes at the same time.

### Move to Dual Boot when

* You're comfortable with Linux.
* You use it daily.
* You need maximum performance for development, Docker, Kubernetes, or other resource-intensive workloads.

---

## There's also a third option: WSL

There's another popular approach called Windows Subsystem for Linux (WSL/WSL2).

Architecture:

```bash
Hardware
    │
Windows
    │
WSL2
    │
Linux Environment
```

It isn't dual boot, and it isn't a traditional VM that you manage yourself. Microsoft provides a lightweight virtualized Linux environment that's tightly integrated with Windows.

It's excellent for:

* C/C++
* Python
* Git
* Docker (with integration)
* Backend development
* Linux command line

You don't get a full Linux desktop by default, but for programming it's often the most convenient option.
