# Installing Libraries

Every sensor folder in this repo lists the exact libraries it needs in its own README. This page explains the two ways to actually install them.

---

## Method 1: Library Manager (use this whenever possible)

This is the easiest and safest method — it handles dependencies automatically.

1. Open Arduino IDE
2. Go to **Sketch → Include Library → Manage Libraries...** (or click the library icon in the left sidebar)
3. Type the library name in the search box (exact names are given in each sensor's README and in [`03-libraries-reference/`](../03-libraries-reference/README.md))
4. Click **Install** on the correct result — double-check the author name, since many sensors have multiple similarly-named libraries
5. If prompted to install dependencies, click **Install All**

---

## Method 2: Manual `.zip` Installation

Use this only when a library isn't available in the Library Manager (rare, but happens with some niche sensor libraries from GitHub).

1. Download the library as a `.zip` from its GitHub repo (green **Code** button → **Download ZIP**)
2. In Arduino IDE: **Sketch → Include Library → Add .ZIP Library...**
3. Select the downloaded `.zip` file — do **not** unzip it first
4. Restart the IDE if the library doesn't show up immediately

---

## Verifying a Library Installed Correctly

Go to **Sketch → Include Library** — your installed library should appear in the dropdown list. If a sketch still shows `fatal error: ... No such file or directory` after installing, see [troubleshooting.md](troubleshooting.md).

---

## Library Index

A running list of every library used across this repo — which sensor/board it's for, and how to install it — is maintained in [`03-libraries-reference/README.md`](../03-libraries-reference/README.md). Check there before installing anything manually; it may already be covered.
