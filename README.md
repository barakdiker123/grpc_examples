


Please visit the page 
[Documentation](https://barakdiker123.github.io/grpc_examples/)
# Some notes on how to create streaming process in elisp 
First one should refer to the documentation of elisp and emacs 


``` emacs-lisp

(print "hello")
(setq var1 (message "Hello %s" "Barak"))
(message var1)
;;(insert "barak")
(setq process1 (start-process "my-lldb-process" "lldb-buffer" "lldb"))
(process-send-string "my-lldb-process" "\n")
(process-send-string "my-lldb-process" "b main\n")
(process-send-string "my-lldb-process" "file /Users/barakdiker/Documents/cpp_project_to_delete/grpc_project/build/greeter_server\n")
(while (accept-process-output process1))
(delete-process "my-lldb-process")

```

`

# Some advance streaming 

Note the following code 

``` emacs-lisp
(let* ((stdout (generate-new-buffer "my-stdout"))
       (stderr (generate-new-buffer "my-stderr"))
       (process (make-process :name "my-program"
                              :command '("/Users/barakdiker/Documents/cpp_project_to_delete/grpc_project/build/main")
                              :buffer stdout
                              :stderr stderr))
       (stderr-process (get-buffer-process stderr)))
  (unless (and process stderr-process)
    (error "Process unexpectedly nil"))
  )

(delete-process "my-program")
(delete-process "my-program<1>")
```

`
and if we want to "join" process 

``` emacs-lisp
(while (accept-process-output process))
(while (accept-process-output stderr-process))
```

`
